/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:40:36 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:39:30 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*var;
	t_diner	*diner;

	if (ft_argc_err(argc) == TRUE)
		return (0);
	var = ft_var_set(argc, argv);
	if (!var)
		return (0);
	diner = ft_diner_set(var);
	ft_thread_exec(diner);
	ft_dinerclear(&diner);
	return (0);
}
