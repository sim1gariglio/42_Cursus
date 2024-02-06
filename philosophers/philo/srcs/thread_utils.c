/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:04 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:39:34 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philodeath(void *diner)
{
	t_bool	flag;
	t_diner	*lst;

	lst = (t_diner *)diner;
	flag = TRUE;
	while (flag == TRUE)
	{
		pthread_mutex_lock(&lst->look);
		if (ft_get_time() > lst->last_meal + lst->time_to_die / 1000)
		{
			pthread_mutex_unlock(&lst->look);
			flag = FALSE;
			ft_mutprint(lst, P_DEATH);
			pthread_mutex_lock(&lst->var->finish);
			lst->var->stop = TRUE;
			pthread_mutex_unlock(&lst->var->finish);
		}
		else
			pthread_mutex_unlock(&lst->look);
		ft_usleep(100);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_threadgen(t_diner **diner)
{
	int		i;
	t_diner	*tmp;

	tmp = *diner;
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		if (ft_threrr(pthread_create(&tmp->id_philo, NULL, ft_think,
					(void *)tmp), diner) == TRUE)
			ft_exit(diner, FALSE);
		i--;
		tmp = tmp->next;
	}
}

t_bool	ft_checkdeath(t_diner *diner)
{
	pthread_mutex_lock(&diner->var->finish);
	if (diner->var->stop == TRUE)
	{
		pthread_mutex_unlock(&diner->var->finish);
		return (TRUE);
	}
	else
		pthread_mutex_unlock(&diner->var->finish);
	return (FALSE);
}

void	*ft_alone(void *arg)
{
	t_var	*var;
	long	begin;

	var = (t_var *)arg;
	begin = ft_get_time();
	pthread_mutex_lock(&var->print);
	printf("%ld 1 is thinking\n", ft_get_time() - begin);
	pthread_mutex_unlock(&var->print);
	pthread_mutex_lock(&var->alone_fork);
	pthread_mutex_lock(&var->print);
	printf("%ld 1 has taken a fork\n", ft_get_time() - begin);
	pthread_mutex_unlock(&var->print);
	ft_usleep(var->time_to_die);
	pthread_mutex_lock(&var->print);
	printf("%ld 1 died\n", ft_get_time() - begin);
	pthread_mutex_unlock(&var->print);
	pthread_mutex_unlock(&var->alone_fork);
	return (NULL);
}

t_bool	ft_solo(t_var *var)
{
	pthread_t		my_thread;

	if (var->nbr_of_philo != 1)
		return (FALSE);
	pthread_mutex_init(&var->alone_fork, NULL);
	if (ft_threrr(pthread_create(&my_thread, NULL, ft_alone,
				(void *)var), NULL) == TRUE)
		ft_exit(NULL, FALSE);
	pthread_join(my_thread, NULL);
	pthread_mutex_destroy(&var->print);
	pthread_mutex_destroy(&var->alone_fork);
	free(var);
	return (TRUE);
}
