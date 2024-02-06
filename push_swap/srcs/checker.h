/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:52:08 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/10 12:16:54 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

typedef enum e_moves
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PA,
	PB,
	WRONG = -1
}	t_moves;

void	ft_domove(t_data *data, char **move, int i);
char	**ft_readmoves(void);
t_bool	ft_checkmtx(char **mtx, int i);
t_moves	ft_checkstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);

t_bool	ft_chk_sa_sb(t_number **stack);
void	ft_chk_ss(t_number **a_stack, t_number **b_stack);
void	ft_chk_pa_pb(t_number **stack_1, t_number **stack_2);
t_bool	ft_chk_ra_rb(t_number **stack);
void	ft_chk_rr(t_number **a_stack, t_number **b_stack);
t_bool	ft_chk_rra_rrb(t_number **stack);
void	ft_chk_rrr(t_number **a_stack, t_number **b_stack);

#endif