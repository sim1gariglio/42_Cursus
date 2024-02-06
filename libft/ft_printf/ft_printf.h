/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:03:01 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/31 10:03:09 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft.h"

int		ft_print_args(va_list args, const char i);
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_freeputstr(const char *str);
char	*ft_uitoa(unsigned int n);
int		ft_printf_pointer(unsigned long int ptr);
int		ft_printf_hex(unsigned long num, const char i);

#endif
