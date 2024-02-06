/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:24 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:02 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	ft_malloc_err(void *ptr)
{
	if (!ptr)
	{
		write(2, "Error: Unexpected malloc behaviour\n", 35);
		exit(EXIT_FAILURE);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_argc_err(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: Wrong input\n", 19);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_threrr(int info, t_data *data)
{
	if (info == 0)
		return (FALSE);
	write(2, "Error: thread can't be created\n", 31);
	ft_freedata(data);
	return (TRUE);
}

void	ft_sem_err(t_data *data)
{
	if (data->chopstick != SEM_FAILED && data->full != SEM_FAILED
		&& data->print != SEM_FAILED && data->death != SEM_FAILED
		&& data->dieall != SEM_FAILED && data->meal != SEM_FAILED
		&& data->semafero != SEM_FAILED)
		return ;
	if (data->chopstick != SEM_FAILED)
		sem_close(data->chopstick);
	if (data->full != SEM_FAILED)
		sem_close(data->full);
	if (data->print != SEM_FAILED)
		sem_close(data->print);
	if (data->death != SEM_FAILED)
		sem_close(data->death);
	if (data->dieall != SEM_FAILED)
		sem_close(data->dieall);
	if (data->meal != SEM_FAILED)
		sem_close(data->meal);
	if (data->semafero != SEM_FAILED)
		sem_close(data->semafero);
	free(data->diner);
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_fork_err(t_data *data, t_diner *diner)
{
	if (diner->pid == -1)
	{
		write(2, "Error: fork failure\n", 20);
		ft_exit(data);
	}
}
