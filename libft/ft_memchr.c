/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:12:08 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/11 14:49:23 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (s == NULL && n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char) c)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
