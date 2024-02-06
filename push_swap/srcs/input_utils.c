/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:21:23 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/09 15:39:04 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_newatoi(char	*str, int *nbr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
		res = res * 10 + str[i] - '0';
		i++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		return (FALSE);
	*nbr = (int)res;
	return (TRUE);
}

t_bool	ft_lstmalchk(t_number *nbr, char ***mtx, t_number **stack, int cl)
{
	if (nbr)
		return (TRUE);
	if (cl == 0)
		ft_mtxdel(mtx);
	ft_nbrclear(stack);
	return (FALSE);
}

void	ft_mtxdel(char ***mtx)
{
	size_t	i;

	i = 0;
	while ((*mtx)[i])
	{
		free((*mtx)[i]);
		i++;
	}
	free(*mtx);
	mtx = NULL;
}
