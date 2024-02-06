/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:14:53 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/16 14:20:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strmaxlen(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;

	max_len = ft_strlen(s);
	if (start > max_len)
		max_len = 0;
	else if (max_len > len)
		max_len = len;
	else if (start < max_len && max_len - start < len)
		max_len -= start;
	return (max_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;
	size_t	max_len;

	i = 0;
	j = 0;
	max_len = ft_strmaxlen(s, start, len);
	dest = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= (size_t)start && j < max_len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}
/*
int	main(int argc, char *argv[])
{
	if(argc != 2)
		return (-1);
	printf("%s\n",ft_substr(argv[1],9,10));
	return (0);
}*/
