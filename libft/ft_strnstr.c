/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:03:49 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/11 14:59:34 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_l;
	size_t	i;
	size_t	j;

	len_l = 0;
	j = 0;
	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (little[len_l])
		len_l++;
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j])
		{
			if (j == len_l - 1 && ((i + j) < len))
				return (&((char *)big)[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int main ()
{
 	char	str[] ="lorem ipsum dolor sit amet";
 	char	to_find[] = "dolor";
	printf("Copia: %s\n", ft_strnstr(str, to_find, 20));
	//printf("Originale: %s", strstr(str, to_find));
 	return 0;
}*/
