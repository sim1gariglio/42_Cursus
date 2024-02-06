/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:59:23 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/13 14:40:34 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    char src[] = "Hello, World!";
    char dest[14];

    ft_memcpy(dest, src, sizeof(src));

    printf("Copia: %s\n", dest);

    char std_dest[14];
    memcpy(std_dest, src, sizeof(src));

    printf("Originale: %s\n", std_dest);

    return 0;
}*/
