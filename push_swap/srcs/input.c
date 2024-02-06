/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:00:54 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/10 12:46:37 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*ft_input1(char *str, int i)
{
	t_number	*stack;
	t_number	*tmp_nbr;
	char		**mtx;
	int			tmp;

	tmp = 0;
	stack = NULL;
	mtx = ft_split(str, ' ');
	if (!mtx)
		return (NULL);
	while (mtx[++i])
	{
		if (ft_newatoi(mtx[i], &tmp) == FALSE)
			tmp_nbr = NULL;
		else
			tmp_nbr = ft_nbrnew(tmp);
		if (ft_lstmalchk(tmp_nbr, &mtx, &stack, 0) == FALSE)
			return (NULL);
		ft_nbradd_back(&stack, tmp_nbr);
	}
	ft_mtxdel(&mtx);
	return (stack);
}

t_number	*ft_input2(int argc, char **argv)
{
	t_number	*stack;
	t_number	*tmp_nbr;
	int			i;
	int			tmp;

	i = 0;
	stack = NULL;
	tmp = 0;
	while (++i < argc && argv[i])
	{
		if (ft_newatoi(argv[i], &tmp) == FALSE)
			tmp_nbr = NULL;
		else
			tmp_nbr = ft_nbrnew(tmp);
		if (ft_lstmalchk(tmp_nbr, &argv, &stack, 1) == FALSE)
			return (NULL);
		ft_nbradd_back(&stack, tmp_nbr);
	}
	return (stack);
}

t_bool	ft_doublecheck(t_number **stack)
{
	t_number	*tmp_nbr;
	t_number	*confront;

	tmp_nbr = *stack;
	while (tmp_nbr->next)
	{
		confront = tmp_nbr->next;
		while (confront)
		{
			if (tmp_nbr->nbr == confront->nbr)
			{
				ft_nbrclear(stack);
				return (FALSE);
			}
			confront = confront->next;
		}
		tmp_nbr = tmp_nbr->next;
	}
	return (TRUE);
}

void	ft_tag_assign(t_number **stack)
{
	t_number	*tmp;
	t_number	*confront1;
	t_number	*confront2;

	tmp = *stack;
	while (tmp)
	{
		confront1 = tmp->next;
		confront2 = tmp->prev;
		while (confront1)
		{
			if (tmp->nbr > confront1->nbr)
				tmp->tag++;
			confront1 = confront1->next;
		}
		while (confront2)
		{
			if (tmp->nbr > confront2->nbr)
				tmp->tag++;
			confront2 = confront2->prev;
		}
		tmp = tmp->next;
	}
}

t_number	*ft_firstackgen(int argc, char **argv)
{
	t_number	*stack;

	if (argc < 2)
		exit(0);
	if (argc == 2)
		stack = ft_input1(argv[1], -1);
	else
		stack = ft_input2(argc, argv);
	if (stack == NULL)
		return (NULL);
	if (ft_doublecheck(&stack) == FALSE)
		return (NULL);
	ft_tag_assign(&stack);
	return (stack);
}
