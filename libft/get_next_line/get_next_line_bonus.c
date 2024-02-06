/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:38:36 by sgarigli          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:30 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		dump = ft_newstrjoin(dump, buff);
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
	char	*returnline;

	i = 0;
	while (dump[i] && dump[i] != '\n')
		i++;
	if (!dump[i])
	{
		free(dump);
		return (NULL);
	}
	returnline = ft_calloc((ft_strlen(dump) - i + 1), sizeof(char));
	if (!returnline)
		return (0);
	i++;
	j = 0;
	while (dump[i])
		returnline[j++] = dump[i++];
	returnline[j] = '\0';
	free(dump);
	return (returnline);
}

char	*get_next_line(int fd)
{
	static char	*dump[4096];
	char		*dst;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	dump[fd] = ft_readline(dump[fd], fd);
	if (!dump[fd])
		return (NULL);
	dst = ft_dstset(dump[fd]);
	dump[fd] = ft_dumpset(dump[fd]);
	return (dst);
}
/*
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str;
	int		i;

	i = 0;
	fd1 = open("ex1.txt", O_RDONLY);
	fd2 = open("ex2.txt", O_RDONLY);
	fd3 = open("ex3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
		return (0);
	while (i < 3)
	{
		str = get_next_line(fd1);
		printf("fd[%d]%s", fd1 - 2, str);
		if(!str)
			printf("\n");
		free(str);
		str = get_next_line(fd3);
		printf("fd[%d]%s", fd3 - 2, str);
		if(!str)
			printf("\n");
		free(str);
		str = get_next_line(fd2);
		printf("fd[%d]%s", fd2 - 2, str);
		if(!str)
			printf("\n");
		free(str);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
