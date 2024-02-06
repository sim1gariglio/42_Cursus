/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:06:01 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/31 10:06:15 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long int num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_printf_pointer(unsigned long int ptr)
{
	int	nbrchr;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	nbrchr = 0;
	nbrchr += write(1, "0x", 2);
	ft_put_ptr(ptr);
	nbrchr += ft_ptr_len(ptr);
	return (nbrchr);
}
