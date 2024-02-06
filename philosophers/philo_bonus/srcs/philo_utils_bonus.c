/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:09:35 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:13 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	ft_malloc_err2(void *ptr, t_data *data)
{
	if (!ptr)
	{
		write(2, "Error: Unexpected malloc behaviour\n", 35);
		free(data);
		exit(EXIT_FAILURE);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_semprint(t_diner *diner, t_data *data, int action)
{
	long	current;

	sem_wait(data->print);
	sem_wait(data->death);
	if (diner->imdead == TRUE)
	{
		sem_post(data->print);
		sem_post(data->death);
		return ;
	}
	sem_post(data->death);
	current = ft_get_time();
	if (action == P_DEATH)
		printf("%ld %d died\n", current - data->starttime, diner->tag);
	else if (action == P_EAT)
		printf("%ld %d is eating\n", current - data->starttime, diner->tag);
	else if (action == P_THINK)
		printf("%ld %d is thinking\n", current - data->starttime, diner->tag);
	else if (action == P_SLEEP)
		printf("%ld %d is sleeping\n", current - data->starttime, diner->tag);
	else if (action == P_FORK)
		printf("%ld %d has taken a fork\n", current - data->starttime,
			diner->tag);
	sem_post(data->print);
}

void	ft_unlink(void)
{
	sem_unlink("Chopstick");
	sem_unlink("Print");
	sem_unlink("Full");
	sem_unlink("Death");
	sem_unlink("Semafero");
	sem_unlink("Dieall");
	sem_unlink("Meal");
}
