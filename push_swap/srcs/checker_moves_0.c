/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:26:44 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 16:47:51 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_bool	ft_chk_sa_sb(t_number **stack)
{
	t_number	*tmp1;
	t_number	*tmp2;

	if (!*stack || !(*stack)->next)
		return (FALSE);
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	if ((*stack)->next->next)
	{
		(*stack)->next->next->prev = tmp1;
		tmp1->next = (*stack)->next->next;
	}
	else
		tmp1->next = NULL;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	tmp2->prev = NULL;
	*stack = tmp2;
	return (TRUE);
}

void	ft_chk_ss(t_number **a_stack, t_number **b_stack)
{
	ft_chk_sa_sb(a_stack);
	ft_chk_sa_sb(b_stack);
}

void	ft_chk_pa_pb(t_number **stack_1, t_number **stack_2)
{
	t_number	*tmp1;

	if (!*stack_1 || !stack_2)
		return ;
	tmp1 = *stack_1;
	if ((*stack_1)->next)
	{
		*stack_1 = (*stack_1)->next;
		(*stack_1)->prev = NULL;
	}
	else
		*stack_1 = NULL;
	ft_nbradd_front(stack_2, tmp1);
}

t_bool	ft_chk_ra_rb(t_number **stack)
{
	t_number	*tmp1;

	if (!stack || !(*stack) || !(*stack)->next)
		return (FALSE);
	if (!(*stack)->next->next)
	{
		ft_chk_sa_sb(stack);
		return (TRUE);
	}
	tmp1 = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp1->next = NULL;
	tmp1->prev = NULL;
	ft_nbradd_back(stack, tmp1);
	return (TRUE);
}

void	ft_chk_rr(t_number **a_stack, t_number **b_stack)
{
	ft_chk_ra_rb(a_stack);
	ft_chk_ra_rb(b_stack);
}
