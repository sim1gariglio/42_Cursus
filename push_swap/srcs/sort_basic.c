/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:38:26 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/10 16:07:08 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_data *data)
{
	if (ft_sorted(&data->a_stack) == TRUE)
		return ;
	if (data->size == 2)
		ft_sa_sb(&data->a_stack, "sa");
	if (data->size == 3)
		ft_sort_3(&data->a_stack);
	else if (data->size == 5)
		ft_sort_5(&data);
	else
		ft_algosort(&data);
}

void	ft_sort_3(t_number **stack)
{
	if (ft_sorted(stack) == TRUE)
		return ;
	if ((*stack)->tag < (*stack)->next->tag)
	{
		if ((*stack)->tag < (*stack)->next->next->tag)
		{
			ft_sa_sb(stack, "sa");
			ft_ra_rb(stack, "ra");
		}
		else
			ft_rra_rrb(stack, "rra");
	}
	else if ((*stack)->next->tag < (*stack)->next->next->tag)
	{
		if ((*stack)->tag < (*stack)->next->next->tag)
			ft_sa_sb(stack, "sa");
		else
			ft_ra_rb(stack, "ra");
	}
	else
	{
		ft_sa_sb(stack, "sa");
		ft_rra_rrb(stack, "rra");
	}
}

void	ft_sort_5(t_data **data)
{
	if (ft_sorted(&((*data)->a_stack)) == TRUE)
		return ;
	while ((*data)->a_stack->tag != 1 && (*data)->a_stack->tag != 2)
		ft_ra_rb(&((*data)->a_stack), "ra");
	ft_pa_pb(&((*data)->a_stack), &((*data)->b_stack), "pb");
	while ((*data)->a_stack->tag != 1 && (*data)->a_stack->tag != 2)
		ft_ra_rb(&((*data)->a_stack), "ra");
	ft_pa_pb(&((*data)->a_stack), &((*data)->b_stack), "pb");
	ft_sort_3(&((*data)->a_stack));
	if (ft_sorted(&((*data)->b_stack)) == TRUE)
		ft_ra_rb(&((*data)->b_stack), "rb");
	ft_pa_pb(&((*data)->b_stack), &((*data)->a_stack), "pa");
	ft_pa_pb(&((*data)->b_stack), &((*data)->a_stack), "pa");
}

void	ft_algosort(t_data	**data)
{
	(*data)->sect = 3 + ((*data)->size) / CONST;
	(*data)->eps = ((*data)->size) / (*data)->sect;
	ft_separation(data, 1, 1, TRUE);
	ft_sort_3(&((*data)->a_stack));
	(*data)->lastag = 0;
	ft_afill(data, (*data)->size - 3);
}
