/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:57:00 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:26:46 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_color(t_info *info, int color, t_colorchange colorchange)
{
	info->index = ((LENGTH * info->y_y) + info->x_x) * 4;
	info->ch[info->index] = (info->itier * info->color + colorchange.keysym
			* (1.0 / 3.0)) * color + (colorchange.b);
	info->ch[info->index + 1] = (info->itier * info->color + colorchange.keysym
			* (1.1 / 3.0)) * color + (colorchange.g);
	info->ch[info->index + 2] = (info->itier * info->color + colorchange.keysym
			* (1.2 / 3.0)) * color + (colorchange.r);
	info->ch[info->index + 3] = 0;
}

void	ft_increase_red(t_info *info)
{
	info->colorchange.r += GRADIENT;
	info->colorchange.r %= 255;
	if (info->itier == info->max)
		ft_set_color(info, 0, info->colorchange);
	else
		ft_set_color(info, 1, info->colorchange);
}

void	ft_increase_green(t_info *info)
{
	info->colorchange.g += GRADIENT;
	info->colorchange.g %= 255;
	if (info->itier == info->max)
		ft_set_color(info, 0, info->colorchange);
	else
		ft_set_color(info, 1, info->colorchange);
}

void	ft_increase_blue(t_info *info)
{
	info->colorchange.b += GRADIENT;
	info->colorchange.b %= 255;
	if (info->itier == info->max)
		ft_set_color(info, 0, info->colorchange);
	else
		ft_set_color(info, 1, info->colorchange);
}
