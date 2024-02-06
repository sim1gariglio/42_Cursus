/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:54:04 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/10 09:55:50 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_bool	ft_chk_rra_rrb(t_number **stack)
{
	t_number	*tmp1;

	if (!stack || !(*stack) || !(*stack)->next)
		return (FALSE);
	if (!(*stack)->next->next)
	{
		ft_chk_sa_sb(stack);
		return (TRUE);
	}
	tmp1 = ft_nbrlast(stack);
	tmp1->prev->next = NULL;
	tmp1->next = *stack;
	tmp1->prev = NULL;
	ft_nbradd_front(stack, tmp1);
	return (TRUE);
}

void	ft_chk_rrr(t_number **a_stack, t_number **b_stack)
{
	ft_chk_rra_rrb(a_stack);
	ft_chk_rra_rrb(b_stack);
}
