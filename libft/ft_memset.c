/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:54 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/11 14:53:31 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((char *)(s))[i] = c;
		i++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char s1[20];
	char s2[20];
	ft_memset(s1, 49, 5);
	memset(s2, 49, 5);
	printf("Copia: %s\n", s1);
	printf("Originale: %s\n",s2);
	return (0);
}*/
