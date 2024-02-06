/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:40:59 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/12 12:48:52 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	ft_mtxsize(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		if (s[i] == '\0')
			return (count);
		i++;
	}
	return (count);
}

static void	ft_row(char const *s, char *row, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		row[i] = s[start];
		start++;
		i++;
	}
	row[i] = '\0';
}

static char	**ft_mtxalloc(char const *s, char c, size_t *start, size_t *end)
{
	size_t	i;
	char	**mtx;

	i = 0;
	mtx = (char **)malloc((ft_mtxsize(s, c) + 1) * sizeof(char *));
	if (mtx == NULL)
		return (NULL);
	while (s[*start] == c && s[*start])
		(*start)++;
	*end = *start;
	while (i < (ft_mtxsize(s, c)))
	{
		while (s[*end] != c && s[*end])
			(*end)++;
		mtx[i] = (char *)malloc((*end - *start + 1) * sizeof(char));
		if (mtx[i] == NULL)
			return (NULL);
		ft_row(s, mtx[i], *start, *end);
		while (s[*end] == c && s[*end])
			(*end)++;
		*start = *end;
		i++;
	}
	mtx[i] = NULL;
	return (mtx);
}

char	**ft_split(char const *s, char c)
{
	char	**mtx;
	size_t	start;
	size_t	end;

	start = 0;
	mtx = ft_mtxalloc(s, c, &start, &end);
	return (mtx);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**mtx = ft_split(" caro amico ti sctivo ! ", ' ');
	size_t	i = 0;

	while (mtx[i])
	{
		printf("mtx[%ld] : %s\n", i, mtx[i]);
		i++;
	}
	return (0);
}*/
