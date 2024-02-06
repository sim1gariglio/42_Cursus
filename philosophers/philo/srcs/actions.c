/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:26:20 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:35:08 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_diner *diner)
{
	if (ft_checkdeath(diner) == TRUE)
		ft_think(diner);
	ft_mutprint(diner, P_SLEEP);
	ft_usleep(diner->time_to_sleep);
	ft_mutprint(diner, P_THINK);
	ft_think(diner);
}

void	ft_eat(t_diner *diner)
{
	if (ft_checkdeath(diner) == TRUE)
		ft_think(diner);
	diner->b_fork = FALSE;
	ft_mutprint(diner, P_FORK);
	diner->next->b_fork = FALSE;
	ft_mutprint(diner, P_FORK);
	pthread_mutex_lock(&diner->look);
	diner->last_meal = ft_get_time();
	pthread_mutex_unlock(&diner->look);
	diner->meal_got++;
	ft_mutprint(diner, P_EAT);
	ft_philofull(diner);
	ft_usleep(diner->time_to_eat);
	diner->b_fork = TRUE;
	diner->next->b_fork = TRUE;
	pthread_mutex_unlock(&diner->next->my_fork);
	pthread_mutex_unlock(&diner->my_fork);
	ft_sleep(diner);
}

void	*ft_think(void *arg)
{
	t_diner	*diner;

	diner = (t_diner *)arg;
	if (ft_checkdeath(diner) == TRUE)
		return (NULL);
	if (diner->meal_got == 0 && diner->tag % 2 == 0)
		ft_usleep(diner->time_to_eat - 900);
	pthread_mutex_lock(&diner->my_fork);
	pthread_mutex_lock(&diner->next->my_fork);
	if (diner->b_fork == TRUE && diner->next->b_fork == TRUE)
		ft_eat(diner);
	else
	{
		pthread_mutex_unlock(&diner->next->my_fork);
		pthread_mutex_unlock(&diner->my_fork);
		ft_think(arg);
	}
	return (NULL);
}

void	ft_philofull(t_diner *diner)
{
	pthread_mutex_lock(&diner->var->eat);
	if (diner->var->nbr_time_philo_eat != 0
		&& diner->meal_got == diner->var->nbr_time_philo_eat)
	{
		diner->var->full++;
		if (diner->var->full >= diner->var->nbr_of_philo)
		{
			ft_mutprint(diner, P_FINISH);
			pthread_mutex_lock(&diner->var->finish);
			diner->var->stop = TRUE;
			pthread_mutex_unlock(&diner->var->finish);
			pthread_mutex_unlock(&diner->var->eat);
			ft_think(diner);
		}
		else
			pthread_mutex_unlock(&diner->var->eat);
	}
	else
		pthread_mutex_unlock(&diner->var->eat);
}
