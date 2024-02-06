/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:35:17 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_var	*ft_var_set(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (ft_malloc_err(var) == TRUE)
		return (NULL);
	var->nbr_of_philo = ft_atoi(av[1]);
	var->time_to_die = ft_atoi(av[2]) * 1000;
	var->time_to_eat = ft_atoi(av[3]) * 1000;
	var->time_to_sleep = ft_atoi(av[4]) * 1000;
	var->nbr_time_philo_eat = 0;
	if (ac == 6)
		var->nbr_time_philo_eat = ft_atoi(av[5]);
	ft_inputcheck(var);
	var->full = 0;
	var->stop = FALSE;
	pthread_mutex_init(&var->print, NULL);
	if (ft_solo(var) == TRUE)
		return (NULL);
	pthread_mutex_init(&var->eat, NULL);
	pthread_mutex_init(&var->finish, NULL);
	return (var);
}

t_bool	ft_inputcheck(t_var *var)
{
	if (var->nbr_of_philo > 0 && var->time_to_die > 0 && var->time_to_eat > 0
		&& var->time_to_sleep > 0 && var->nbr_time_philo_eat >= 0)
		return (TRUE);
	write(2, "Error: Wrong input\n", 19);
	free(var);
	exit (EXIT_SUCCESS);
}

t_diner	*ft_diner_set(t_var *var)
{
	t_diner	*diner;
	int		i;

	diner = NULL;
	i = var->nbr_of_philo;
	while (i > 1)
	{
		ft_dineradd_back(&diner, ft_dinernew(&diner, var));
		i--;
	}
	ft_dineradd_last(&diner, ft_dinernew(&diner, var));
	ft_begin(&diner);
	return (diner);
}

void	ft_begin(t_diner **diner)
{
	int		i;
	long	now;
	t_diner	*tmp;

	tmp = *diner;
	now = ft_get_time();
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		tmp->start_time = now;
		tmp->last_meal = ft_get_time();
		ft_mutprint(tmp, P_THINK);
		i--;
		tmp = tmp->next;
	}
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		tmp->b_fork = TRUE;
		i--;
		tmp = tmp->next;
	}
}

void	ft_thread_exec(t_diner *diner)
{
	int			i;
	t_diner		*tmp;
	pthread_t	undertaker;

	ft_threadgen(&diner);
	if (ft_threrr(pthread_create(&undertaker, NULL, ft_philodeath,
				(void *)diner), &diner) == TRUE)
		ft_exit(&diner, FALSE);
	tmp = diner;
	i = tmp->nbr_of_philo;
	while (i)
	{
		pthread_join(tmp->id_philo, NULL);
		tmp = tmp->next;
		i--;
	}
	pthread_join(undertaker, NULL);
}
