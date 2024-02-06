/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:38:08 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 16:53:18 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_separation(t_data **data, int i, int j, t_bool flag)
{
	while (ft_maxtag(&((*data)->a_stack)) > 3)
	{
		flag = TRUE;
		if ((*data)->a_stack->tag <= (*data)->eps * j
			&& (*data)->a_stack->tag <= ((*data)->size - 3))
		{
			ft_pa_pb(&((*data)->a_stack), &((*data)->b_stack), "pb");
			i++;
		}
		else if ((*data)->a_stack->tag <= (*data)->eps * (j + 1)
			&& (*data)->a_stack->tag <= ((*data)->size - 3))
		{
			ft_pa_pb(&((*data)->a_stack), &((*data)->b_stack), "pb");
			flag = ft_optimus_prime(data, j);
			i++;
		}
		else if (flag == TRUE)
			ft_ra_rb(&((*data)->a_stack), "ra");
		ft_nextsect(data, &i, &j);
	}
}

void	ft_afill(t_data	**data, int find)
{
	while (ft_sorted(&(*data)->a_stack) || ft_maxtag(&(*data)->a_stack) == 3
		|| (*data)->b_stack)
	{
		if (ft_upordown(data, find) == A)
		{
			ft_rra_rrb(&((*data)->a_stack), "rra");
			(*data)->lastag = ft_nbrlast(&(*data)->a_stack)->tag;
			if ((*data)->lastag == (*data)->size)
				(*data)->lastag = 0;
			find--;
		}
		if (ft_upordown(data, find) == DOWN)
			ft_godown(data, &find);
		else if (ft_upordown(data, find) == UP)
			ft_goup(data, &find);
	}
}
