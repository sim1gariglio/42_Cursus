/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:53:34 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/10 12:33:05 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**moves;

	data.a_stack = ft_firstackgen(argc, argv);
	data.b_stack = NULL;
	if (!data.a_stack)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	data.size = ft_maxtag(&data.a_stack);
	moves = ft_readmoves();
	if (!moves)
	{
		ft_freedata(&data);
		return (0);
	}
	ft_domove(&data, moves, -1);
	ft_mtxdel(&moves);
	if (ft_sorted(&data.a_stack) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_freedata(&data);
	return (0);
}
