/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:53:52 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:22:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_info	*info)
{
	mlx_clear_window(info->ptr, info->win);
	info->y_y = 0;
	while (info->y_y < HEIGHT)
	{
		info->x_x = 0;
		while (info->x_x < WIDTH)
		{
			info->itier = 0;
			ft_map(info);
			ft_itier_loop(info);
			if (info->itier == info->max)
				ft_set_color(info, 0, info->colorchange);
			else
				ft_set_color(info, 1, info->colorchange);
			info->x_x++;
		}
		info->y_y++;
	}
	info->stop = 1;
	ft_mlx_hook(info);
}

void	julia(t_info *info)
{
	mlx_clear_window(info->ptr, info->win);
	info->y_y = 0;
	while (info->y_y < HEIGHT)
	{
		info->x_x = 0;
		while (info->x_x < WIDTH)
		{
			info->itier = 0;
			ft_map(info);
			ft_itier_loop2(info);
			if (info->itier == info->max)
				ft_set_color(info, 0, info->colorchange);
			else
				ft_set_color(info, 1, info->colorchange);
			info->x_x++;
		}
		info->y_y++;
	}
	info->stop = 1;
	ft_mlx_hook(info);
}

void	custom(t_info	*info)
{
	mlx_clear_window(info->ptr, info->win);
	info->y_y = 0;
	while (info->y_y < HEIGHT)
	{
		info->x_x = 0;
		while (info->x_x < WIDTH)
		{
			info->itier = 0;
			ft_map(info);
			ft_itier_loop3(info);
			if (info->itier == info->max)
				ft_set_color(info, 0, info->colorchange);
			else
				ft_set_color(info, 1, info->colorchange);
			info->x_x++;
		}
		info->y_y++;
	}
	info->stop = 1;
	ft_mlx_hook(info);
}
