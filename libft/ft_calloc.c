/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:52:38 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/11 14:47:48 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 0 && (size > 2147483647 / nmemb))
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!(ptr))
		return (NULL);
	ft_memset (ptr, 0, size * nmemb);
	return (ptr);
}
