/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:07:09 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/31 10:07:12 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_10pow(int exp)
{
	size_t	pow;

	pow = 1;
	while (exp > 1)
	{
		pow *= 10;
		exp--;
	}
	return (pow);
}

static size_t	ft_unlen(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_ufilldest(char *dest, size_t len, unsigned long int nmb)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = (nmb / (ft_10pow(len - i))) + '0';
		nmb = nmb % (ft_10pow(len - i));
		i++;
	}
	dest[i] = 0;
}

char	*ft_uitoa(unsigned int n)
{
	size_t				len;
	char				*dest;
	unsigned long int	nmb;

	nmb = n;
	len = ft_unlen(n);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_ufilldest(dest, len, nmb);
	return (dest);
}
