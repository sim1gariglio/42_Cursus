/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:00:41 by sgarigli          #+#    #+#             */
/*   Updated: 2023/11/13 12:12:30 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_checkendl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_newstrjoin(char *dump, char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!buff)
		return (NULL);
	if (!dump)
		dump = ft_calloc(1, sizeof(char));
	if (!dump)
		return (NULL);
	res = ft_calloc((ft_strlen(dump) + ft_strlen(buff) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (dump)
		while (dump[++i] != '\0')
			res[i] = dump[i];
	while (buff[j] != '\0')
		res[i++] = buff[j++];
	res[ft_strlen(dump) + ft_strlen(buff)] = '\0';
	free(dump);
	return (res);
}
