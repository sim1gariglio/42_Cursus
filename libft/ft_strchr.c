/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:13:50 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/13 14:32:24 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == 0)
			return (NULL);
		str++;
	}
	return (str);
}
/*
int	main(void)
{
	char	*result = ft_strchr("tripouille", 't' + 256);
	if (result != NULL)
		printf("%s\n", result);
	if (result == NULL)
                printf("(null)");
	return (0);
}*/
