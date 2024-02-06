/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:37 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/12 11:24:54 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	while ((*nptr <= 13 && *nptr >= 9) || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		nb *= 10;
		nb = nb + (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}
/*
int	main(void)
{
	char	*s = "  +-1234567";

	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}*/
