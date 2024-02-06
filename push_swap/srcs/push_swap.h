/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:55:55 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 16:52:24 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ftprintf/ft_printf.h"
# include "limits.h"

# define CONST 50

typedef enum e_direction
{
	UP,
	DOWN,
	A
}	t_direction;

typedef struct s_number
{
	int				nbr;
	int				tag;
	struct s_number	*prev;
	struct s_number	*next;
}	t_number;

typedef struct s_data
{
	int			eps;
	int			sect;
	int			size;
	int			lastag;
	t_number	*a_stack;
	t_number	*b_stack;
}	t_data;

t_number	*ft_firstackgen(int argc, char **argv);
void		ft_mtxdel(char ***mtx);
t_bool		ft_newatoi(char	*str, int *nbr);
t_number	*ft_nbrnew(int content);
void		ft_nbrclear(t_number **lst);
void		ft_nbradd_back(t_number **lst, t_number *new);
void		ft_nbradd_front(t_number **lst, t_number *new);
t_number	*ft_nbrlast(t_number **stack);
t_bool		ft_lstmalchk(t_number *nbr, char ***mtx, t_number **stack, int cl);

t_bool		ft_sa_sb(t_number **stack, char *move);
void		ft_ss(t_number **a_stack, t_number **b_stack);
void		ft_pa_pb(t_number **stack_1, t_number **stack_2, char *move);
t_bool		ft_ra_rb(t_number **stack, char *move);
void		ft_rr(t_number **a_stack, t_number **b_stack);
t_bool		ft_rra_rrb(t_number **stack, char *move);
void		ft_rrr(t_number **a_stack, t_number **b_stack);

void		ft_tag_assign(t_number **stack);
int			ft_maxtag(t_number **stack);
t_direction	ft_upordown(t_data **data, int find);
void		ft_movelse(t_data **data);
void		ft_freedata(t_data *data);

void		ft_algosort(t_data	**data);
t_bool		ft_sorted(t_number **stack);
void		ft_sort(t_data *data);
void		ft_sort_3(t_number **stack);
void		ft_sort_5(t_data **data);

void		ft_separation(t_data **data, int i, int j, t_bool flag);
void		ft_afill(t_data	**data, int find);
void		ft_godown(t_data **data, int *find);
void		ft_goup(t_data **data, int *find);
t_bool		ft_optimus_prime(t_data **data, int j);
void		ft_nextsect(t_data **data, int *i, int *j);

#endif
