/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:12:50 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 16:51:55 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_godown(t_data **data, int *find)
{
	while ((*data)->b_stack->tag != *find)
	{
		if ((*data)->b_stack->tag > (*data)->lastag)
			ft_movelse(data);
		else
			ft_rra_rrb(&((*data)->b_stack), "rrb");
	}
	ft_pa_pb(&((*data)->b_stack), &((*data)->a_stack), "pa");
	(*find)--;
}

void	ft_goup(t_data **data, int *find)
{
	while ((*data)->b_stack->tag != *find)
	{
		if ((*data)->b_stack->tag > (*data)->lastag)
			ft_movelse(data);
		else
			ft_ra_rb(&((*data)->b_stack), "rb");
	}
	ft_pa_pb(&((*data)->b_stack), &((*data)->a_stack), "pa");
	(*find)--;
}

void	ft_nextsect(t_data **data, int *i, int *j)
{
	if ((*i) > ((*data)->eps) * 2)
	{
		(*i) = 1;
		(*j) += 2;
	}
}

t_bool	ft_optimus_prime(t_data **data, int j)
{
	if (!(((*data)->a_stack->tag <= (*data)->eps * j
				|| (*data)->a_stack->tag <= (*data)->eps * (j + 1))
			&& (*data)->a_stack->tag <= ((*data)->size - 3)))
	{
		ft_rr(&(*data)->a_stack, &(*data)->b_stack);
		return (FALSE);
	}
	ft_ra_rb(&((*data)->b_stack), "rb");
	return (TRUE);
}
