/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:02:17 by sgarigli          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:22 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_readline(char *dump, int fd);
size_t	ft_strlen(char *str);
int		ft_checkendl(char *s);
char	*ft_strjoin(char *dump, char *buff);
char	*ft_dstset(char *dump);
char	*ft_dumpset(char *dump);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
