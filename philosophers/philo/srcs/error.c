/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:24 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:35:14 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_malloc_err(void *ptr)
{
	if (!ptr)
	{
		write(2, "Error: Unexpected malloc behaviour\n", 35);
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

t_bool	ft_muterr(int info, t_diner **diner)
{
	if (info == 0)
		return (FALSE);
	write(2, "Error: mutex init failed\n", 25);
	ft_dinerclear(diner);
	return (TRUE);
}

t_bool	ft_threrr(int info, t_diner **diner)
{
	if (info == 0)
		return (FALSE);
	write(2, "Error: thread can't be created\n", 31);
	ft_dinerclear(diner);
	return (TRUE);
}
