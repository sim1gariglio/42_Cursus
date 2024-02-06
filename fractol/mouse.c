/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:36:43 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:20:34 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_mouse(int button, int x, int y, t_info *info)
{
	if (button == 5 && info->stop == 1)
	{
		ft_zoom(info, (double)x, (double)y, ZOOMOUT);
		info->zoomfactor /= 1.4;
	}
	else if (button == 4 && info->stop == 1)
	{
		ft_zoom(info, (double)x, (double)y, ZOOMIN);
		info->zoomfactor *= 1.4;
	}
	ft_check_argv(info);
	return (0);
}

void	ft_zoom(t_info *info, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (info->end_x - info->start_x)) + info->start_x;
	yy = ((y / HEIGHT) * (info->end_y - info->start_y)) + info->start_y;
	info->start_x = xx + (info->start_x - xx) * zoom;
	info->start_y = yy + (info->start_y - yy) * zoom;
	info->end_y = yy + (info->end_y - yy) * zoom;
	info->end_x = xx + (info->end_x - xx) * zoom;
	if (info->max <= 200)
		info->max += 2;
}

int	ft_x_button(t_info	*info)
{
	mlx_destroy_image(info->ptr, info->img);
	mlx_destroy_window(info->ptr, info->win);
	mlx_destroy_display(info->ptr);
	free(info->ptr);
	exit(1);
}
