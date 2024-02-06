/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:54:04 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/09 15:39:13 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_rra_rrb(t_number **stack, char *move)
{
	t_number	*tmp1;

	if (!stack || !(*stack) || !(*stack)->next)
		return (FALSE);
	if (!(*stack)->next->next)
	{
		ft_sa_sb(stack, move);
		return (TRUE);
	}
	tmp1 = ft_nbrlast(stack);
	tmp1->prev->next = NULL;
	tmp1->next = *stack;
	tmp1->prev = NULL;
	ft_nbradd_front(stack, tmp1);
	if (move)
		ft_printf("%s\n", move);
	return (TRUE);
}

void	ft_rrr(t_number **a_stack, t_number **b_stack)
{
	t_bool	a;
	t_bool	b;

	a = ft_rra_rrb(a_stack, NULL);
	b = ft_rra_rrb(b_stack, NULL);
	if (a == FALSE && b == FALSE)
		return ;
	ft_printf("rrr\n");
}
