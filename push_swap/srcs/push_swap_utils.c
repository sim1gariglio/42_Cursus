/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:17 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/09 15:38:36 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_sorted(t_number **stack)
{
	t_number	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next && tmp->nbr > tmp->next->nbr)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	ft_maxtag(t_number **stack)
{
	int			maxtag;
	t_number	*tmp;

	tmp = *stack;
	maxtag = 0;
	while (tmp)
	{
		maxtag++;
		tmp = tmp->next;
	}
	return (maxtag);
}

t_direction	ft_upordown(t_data **data, int find)
{
	int			dist;
	t_number	*tmp;

	dist = 0;
	tmp = (*data)->b_stack;
	while (tmp && tmp->tag != find)
	{
		tmp = tmp->next;
		dist++;
	}
	if (!tmp)
		return (A);
	if (dist > ft_maxtag(&(*data)->b_stack) / 2)
		return (DOWN);
	return (UP);
}

void	ft_movelse(t_data **data)
{
	(*data)->lastag = (*data)->b_stack->tag;
	ft_pa_pb(&((*data)->b_stack), &((*data)->a_stack), "pa");
	ft_ra_rb(&((*data)->a_stack), "ra");
}

void	ft_freedata(t_data *data)
{
	ft_nbrclear(&data->a_stack);
	ft_nbrclear(&data->b_stack);
}
