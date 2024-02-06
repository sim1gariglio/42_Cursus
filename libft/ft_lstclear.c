/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:20:19 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/16 12:37:07 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst == NULL || *lst == NULL)
		return ;
	if (del == NULL)
		return ;
	while (*lst != NULL)
	{
		current = *lst;
		*lst = (*lst)->next;
		del(current->content);
		free(current);
	}
}
