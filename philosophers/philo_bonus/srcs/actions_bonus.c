/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:13:24 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:39:59 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_control(t_data *data, t_diner *diner)
{
	sem_wait(data->death);
	if (diner->imdead == TRUE)
	{
		sem_post(data->death);
		pthread_join(diner->philokill, NULL);
		ft_exit(data);
	}
	else
		sem_post(data->death);
	ft_usleep(1000);
}

void	ft_think(t_data *data, t_diner *diner)
{
	ft_control(data, diner);
	ft_semprint(diner, data, P_THINK);
	if (diner->tag % 2 == 0 && diner->mealgot == 0)
		ft_usleep(diner->var.time_to_eat / 2);
	sem_wait(data->semafero);
	sem_wait(data->chopstick);
	ft_semprint(diner, data, P_FORK);
	sem_wait(data->chopstick);
	ft_semprint(diner, data, P_FORK);
	sem_post(data->semafero);
	ft_eat(data, diner);
}

void	ft_eat(t_data *data, t_diner *diner)
{
	ft_control(data, diner);
	ft_semprint(diner, data, P_EAT);
	sem_wait(data->meal);
	diner->lastmeal = ft_get_time();
	sem_post(data->meal);
	diner->mealgot++;
	if (diner->mealgot == diner->var.nbr_time_philo_eat)
		sem_post(data->full);
	ft_control(data, diner);
	if (data->var.time_to_eat > data->var.time_to_die)
		ft_usleep(data->var.time_to_die);
	else
		ft_usleep(data->var.time_to_eat);
	sem_post(data->chopstick);
	sem_post(data->chopstick);
	ft_sleep(data, diner);
}

void	ft_sleep(t_data *data, t_diner *diner)
{
	ft_control(data, diner);
	ft_semprint(diner, data, P_SLEEP);
	if (data->var.time_to_eat
		+ data->var.time_to_sleep > data->var.time_to_die)
		ft_usleep(data->var.time_to_die - data->var.time_to_eat);
	else
		ft_usleep(data->var.time_to_sleep);
	ft_think(data, diner);
}

void	ft_solo(t_data *data, t_diner *diner)
{
	if (data->var.nbr_of_philo != 1)
		return ;
	ft_semprint(diner, data, P_THINK);
	sem_wait(data->semafero);
	sem_wait(data->chopstick);
	ft_semprint(diner, data, P_FORK);
	sem_post(data->semafero);
	ft_usleep(data->var.time_to_die);
	sem_post(data->chopstick);
	ft_semprint(diner, data, P_DEATH);
	ft_exit(data);
}
