/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:43:07 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/11 14:56:01 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*news;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	news = (char *) malloc((len + 1) * sizeof (char));
	if (!(news))
		return (NULL);
	while (s[i])
	{
		news[i] = s[i];
		i++;
	}
	news[i] = 0;
	return (news);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	printf("%s\n", ft_strdup(argv[1]));
	printf("%s\n",strdup(argv[1]));
	return (0);
}*/
