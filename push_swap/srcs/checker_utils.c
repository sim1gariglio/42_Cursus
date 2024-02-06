/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:58:51 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/10 16:28:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_domove(t_data *data, char **move, int i)
{
	while (move[++i])
	{
		if (ft_checkstr(move[i]) == SA)
			ft_chk_sa_sb(&data->a_stack);
		if (ft_checkstr(move[i]) == SB)
			ft_chk_sa_sb(&data->b_stack);
		if (ft_checkstr(move[i]) == SS)
			ft_chk_ss(&data->a_stack, &data->b_stack);
		if (ft_checkstr(move[i]) == RA)
			ft_chk_ra_rb(&data->a_stack);
		if (ft_checkstr(move[i]) == RB)
			ft_chk_ra_rb(&data->b_stack);
		if (ft_checkstr(move[i]) == RR)
			ft_chk_rr(&data->a_stack, &data->b_stack);
		if (ft_checkstr(move[i]) == RRA)
			ft_chk_rra_rrb(&data->a_stack);
		if (ft_checkstr(move[i]) == RRB)
			ft_chk_rra_rrb(&data->b_stack);
		if (ft_checkstr(move[i]) == RRR)
			ft_chk_rrr(&data->a_stack, &data->b_stack);
		if (ft_checkstr(move[i]) == PB)
			ft_chk_pa_pb(&data->a_stack, &data->b_stack);
		if (ft_checkstr(move[i]) == PA)
			ft_chk_pa_pb(&data->b_stack, &data->a_stack);
	}
}

char	**ft_readmoves(void)
{
	char	*moves;
	char	*buff;
	char	**mtx;
	int		bytesread;

	bytesread = 1;
	moves = ft_calloc(BUFFER_SIZE, sizeof(char));
	buff = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!moves || !buff)
		return (NULL);
	while (buff)
	{
		moves = ft_newstrjoin(moves, buff);
		free(buff);
		buff = get_next_line(STDIN_FILENO);
	}
	mtx = ft_split(moves, '\n');
	free(moves);
	if (!mtx)
		return (NULL);
	if (ft_checkmtx(mtx, 0) == FALSE)
		return (NULL);
	return (mtx);
}

t_bool	ft_checkmtx(char **mtx, int i)
{
	while (mtx[i])
	{
		if (ft_checkstr(mtx[i]) == WRONG)
		{
			ft_mtxdel(&mtx);
			write(2, "Error\n", 6);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_moves	ft_checkstr(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (SA);
	if (ft_strcmp(str, "sb") == 0)
		return (SB);
	if (ft_strcmp(str, "ss") == 0)
		return (SS);
	if (ft_strcmp(str, "ra") == 0)
		return (RA);
	if (ft_strcmp(str, "rb") == 0)
		return (RB);
	if (ft_strcmp(str, "rr") == 0)
		return (RR);
	if (ft_strcmp(str, "rra") == 0)
		return (RRA);
	if (ft_strcmp(str, "rrb") == 0)
		return (RRB);
	if (ft_strcmp(str, "rrr") == 0)
		return (RRR);
	if (ft_strcmp(str, "pa") == 0)
		return (PA);
	if (ft_strcmp(str, "pb") == 0)
		return (PB);
	return (WRONG);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	i = 0;
	if (!s1 || !s2)
		return (INT_MIN);
	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	while (un_s1[i] && un_s2[i] && un_s1[i] == un_s2[i])
		i++;
	return ((int)(un_s1[i] - un_s2[i]));
}
