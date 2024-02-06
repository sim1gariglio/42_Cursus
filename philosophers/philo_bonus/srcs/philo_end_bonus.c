/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:52:34 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:11 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_freedata(t_data *data)
{
	sem_close(data->chopstick);
	sem_close(data->print);
	sem_close(data->full);
	sem_close(data->semafero);
	sem_close(data->death);
	sem_close(data->dieall);
	sem_close(data->meal);
	free(data->diner);
	free(data);
}

void	ft_exit(t_data *data)
{
	sem_post(data->chopstick);
	ft_freedata(data);
	exit(EXIT_SUCCESS);
}

void	ft_wait(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->var.nbr_of_philo)
	{
		data->diner[i].finished_pid = waitpid(-1, &data->diner[i].status, 0);
		if (!WIFEXITED(data->diner[i].status))
			printf("Child process with PID %d has terminated abnormally.\n",
				data->diner[i].finished_pid);
		i++;
	}
	if (data->var.nbr_time_philo_eat > 0 && data->var.nbr_of_philo > 1)
	{
		while (data->var.nbr_time_philo_eat > 0)
		{
			sem_post(data->full);
			data->var.nbr_time_philo_eat--;
		}
		pthread_join(data->ciccio, NULL);
	}
}
