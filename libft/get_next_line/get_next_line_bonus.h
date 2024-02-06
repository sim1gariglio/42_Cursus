/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:39:22 by sgarigli          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:43 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft.h"

char	*get_next_line(int fd);
char	*ft_readline(char *dump, int fd);
int		ft_checkendl(char *s);
char	*ft_newstrjoin(char *dump, char *buf);
char	*ft_dstset(char *dump);
char	*ft_dumpset(char *dump);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
