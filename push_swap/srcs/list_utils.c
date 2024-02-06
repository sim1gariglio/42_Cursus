/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:27:22 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/09 15:35:52 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*ft_nbrnew(int content)
{
	t_number	*my_list;

	my_list = (t_number *)malloc(sizeof(t_number));
	if (!my_list)
		return (NULL);
	my_list->nbr = content;
	my_list->tag = 1;
	my_list->next = NULL;
	my_list->prev = NULL;
	return (my_list);
}

void	ft_nbrclear(t_number **lst)
{
	t_number	*tofree_lst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tofree_lst = *lst;
		*lst = (*lst)->next;
		free(tofree_lst);
	}
	lst = NULL;
}

void	ft_nbradd_back(t_number **lst, t_number *new)
{
	t_number	*tmp_lst;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp_lst = ft_nbrlast(lst);
		tmp_lst->next = new;
		new->prev = tmp_lst;
	}
}

void	ft_nbradd_front(t_number **lst, t_number *new)
{
	t_number	*tmp;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		tmp = (*lst);
		tmp->prev = new;
		new->next = tmp;
		new->prev = NULL;
		*lst = new;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
	}
}

t_number	*ft_nbrlast(t_number **stack)
{
	t_number	*lst;

	lst = *stack;
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
