/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:32:28 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:15 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_philofull(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->var.nbr_of_philo)
	{
		sem_wait(data->full);
		i++;
	}
	sem_post(data->dieall);
	return (NULL);
}

void	*ft_philodied(void *arg)
{
	t_diner	*diner;

	diner = (t_diner *)arg;
	sem_wait(diner->data->dieall);
	sem_wait(diner->data->death);
	diner->imdead = TRUE;
	sem_post(diner->data->death);
	sem_post(diner->data->dieall);
	pthread_join(diner->undertaker, NULL);
	return (NULL);
}

t_bool	ft_otherdied(t_diner *diner)
{
	sem_wait(diner->data->death);
	if (diner->imdead == TRUE)
	{
		sem_post(diner->data->death);
		return (TRUE);
	}
	else
		sem_post(diner->data->death);
	return (FALSE);
}

void	*ft_checkdeath(void *arg)
{
	t_diner	*diner;
	t_bool	check;

	diner = (t_diner *)arg;
	check = FALSE;
	while (check == FALSE)
	{
		if (ft_otherdied(diner) == TRUE)
			return (NULL);
		sem_wait(diner->data->meal);
		if (ft_get_time() > diner->lastmeal + diner->var.time_to_die / 1000)
		{
			sem_post(diner->data->meal);
			ft_semprint(diner, diner->data, P_DEATH);
			sem_post(diner->data->dieall);
			check = TRUE;
		}
		else
			sem_post(diner->data->meal);
		ft_usleep(1000);
	}
	return (NULL);
}
