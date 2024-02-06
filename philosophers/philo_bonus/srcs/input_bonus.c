/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:06 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_var	ft_var_set(int ac, char **av)
{
	t_var	var;

	var.nbr_of_philo = ft_atoi(av[1]);
	var.time_to_die = ft_atoi(av[2]) * 1000;
	var.time_to_eat = ft_atoi(av[3]) * 1000;
	var.time_to_sleep = ft_atoi(av[4]) * 1000;
	var.nbr_time_philo_eat = 0;
	if (ac == 6)
		var.nbr_time_philo_eat = ft_atoi(av[5]);
	return (var);
}

t_bool	ft_inputcheck(t_var var, t_data *data)
{
	if (var.nbr_of_philo > 0 && var.time_to_die > 0 && var.time_to_eat > 0
		&& var.time_to_sleep > 0 && var.nbr_time_philo_eat >= 0)
		return (TRUE);
	write(2, "Error: Wrong input\n", 19);
	free(data);
	exit (EXIT_FAILURE);
}

t_data	*ft_datagen(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	ft_malloc_err(data);
	data->var = ft_var_set(ac, av);
	ft_inputcheck(data->var, data);
	data->diner = malloc(data->var.nbr_of_philo * sizeof(t_diner));
	ft_malloc_err2(data->diner, data);
	data->chopstick = sem_open("Chopstick", O_CREAT, 0666,
			data->var.nbr_of_philo);
	data->full = sem_open("Full", O_CREAT, 0666, 0);
	data->print = sem_open("Print", O_CREAT, 0666, 1);
	data->death = sem_open("Death", O_CREAT, 0666, 1);
	data->semafero = sem_open("Semafero", O_CREAT, 0666, 1);
	data->dieall = sem_open("Dieall", O_CREAT, 0666, 0);
	data->meal = sem_open("Meal", O_CREAT, 0666, 1);
	ft_sem_err(data);
	data->total_meal = 0;
	data->i_full = 0;
	data->b_death = FALSE;
	return (data);
}

void	ft_philo_init(t_diner *diner, t_data *data, int i)
{
	diner->mealgot = 0;
	diner->lastmeal = ft_get_time();
	diner->tag = i + 1;
	diner->starttime = data->starttime;
	diner->data = data;
	diner->imdead = FALSE;
	if (data->var.nbr_of_philo == 1)
		return ;
	if (ft_threrr(pthread_create(&diner->undertaker, NULL, ft_checkdeath,
				diner), data) == TRUE)
		exit(EXIT_FAILURE);
	if (ft_threrr(pthread_create(&diner->philokill, NULL, ft_philodied,
				diner), data) == TRUE)
		exit(EXIT_FAILURE);
}

void	ft_philo_gen(t_data *data)
{
	int	i;

	i = 0;
	data->starttime = ft_get_time();
	while (i < data->var.nbr_of_philo)
	{
		data->diner[i].pid = fork();
		ft_fork_err(data, &data->diner[i]);
		if (data->diner[i].pid == 0)
		{
			data->diner[i].var = data->var;
			ft_philo_init(&data->diner[i], data, i);
			ft_solo(data, &data->diner[i]);
			ft_think(data, &data->diner[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
		usleep(100);
	}
	if (data->var.nbr_time_philo_eat > 0 && data->var.nbr_of_philo > 1)
		if (ft_threrr(pthread_create(&data->ciccio, NULL, ft_philofull,
					data), data) == TRUE)
			exit(EXIT_FAILURE);
}
