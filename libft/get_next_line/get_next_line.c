/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:23:29 by sgarigli          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:14 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *dump, int fd)
{
	char	*buff;
	int		len;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	len = 1;
	while (len > 0 && ft_checkendl(dump) == 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(dump);
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		dump = ft_strjoin(dump, buff);
	}
	free(buff);
	return (dump);
}

char	*ft_dstset(char *dump)
{
	char	*dst;
	int		i;

	i = 0;
	if (!dump[i])
		return (NULL);
	while (dump[i] && dump[i] != '\n')
		i++;
	dst = ft_calloc((i + 2), sizeof(char));
	if (!dst)
		return (0);
	i = 0;
	while (dump[i] && dump[i] != '\n')
	{
		dst[i] = dump[i];
		i++;
	}
	if (dump[i] == '\n')
	{
		dst[i] = dump[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_dumpset(char *dump)
{
	int		i;
	int		j;
	char	*newdump;

	i = 0;
	while (dump[i] && dump[i] != '\n')
		i++;
	if (!dump[i])
	{
		free(dump);
		return (NULL);
	}
	newdump = ft_calloc((ft_strlen(dump) - i + 1), sizeof(char));
	if (!newdump)
		return (0);
	i++;
	j = 0;
	while (dump[i])
		newdump[j++] = dump[i++];
	newdump[j] = '\0';
	free(dump);
	return (newdump);
}

char	*get_next_line(int fd)
{
	static char	*dump = NULL;
	char		*dst;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	dump = ft_readline(dump, fd);
	if (!dump)
		return (NULL);
	dst = ft_dstset(dump);
	dump = ft_dumpset(dump);
	return (dst);
}

/*
int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("prova.txt", O_RDONLY);
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return (0);
}*/
