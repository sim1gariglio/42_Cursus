/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:01:31 by sgarigli          #+#    #+#             */
/*   Updated: 2023/10/09 11:17:06 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int nm)
{
	if (nm <= '9' && nm >= '0')
		return (1);
	return (0);
}
