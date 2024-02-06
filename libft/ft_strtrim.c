/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:25 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/13 14:39:59 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	ft_newstart(char const *s1, char const *set)
{
	size_t	j;
	size_t	start;
	int		flag;

	start = 0;
	flag = 0;
	while (s1[start] != 0 && flag == 0)
	{
		flag = 1;
		j = 0;
		while (set[j] && flag == 1)
		{
			if (s1[start] == set[j])
				flag = 0;
			j++;
		}
		start++;
	}
	start--;
	return (start);
}

static size_t	ft_newend(char const *s1, char const *set)
{
	size_t	j;
	size_t	end;
	int		flag;

	end = ft_strlen(s1);
	flag = 0;
	while (end != 0 && flag == 0)
	{
		j = 0;
		flag = 1;
		while (set[j] != 0 && flag == 1)
		{
			if (s1[end - 1] == set[j])
				flag = 0;
			j++;
		}
		end--;
	}
	end++;
	return (end);
}

static void	ft_newdest(char const *s1, char *dest, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	size_t		start;
	size_t		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_newstart(s1, set);
	end = ft_newend(s1, set);
	if (start > end)
	{
		dest = (char *)malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	ft_newdest(s1, dest, start, end);
	return (dest);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (-1);
	char *trimmed_str = ft_strtrim(argv[1], argv[2]);
	printf("%s\n", trimmed_str);
	free (trimmed_str);
	return (0);
}*/
