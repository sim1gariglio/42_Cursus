/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:16 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:04:45 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrow_press(t_info *info, int keysym)
{
	double	xx;
	double	yy;
	t_arrow	arrow;

	ft_arrowinit(&arrow);
	if (keysym == XK_Right)
		arrow.right += MOVEMENT;
	if (keysym == XK_Left)
		arrow.left += MOVEMENT;
	if (keysym == XK_Down)
		arrow.down += MOVEMENT;
	if (keysym == XK_Up)
		arrow.up += MOVEMENT;
	xx = ((info->end_x - info->start_x)) + info->start_x;
	yy = ((info->end_y - info->start_y)) + info->start_y;
	info->start_x = xx + (info->start_x - xx) + (arrow.right - arrow.left)
		/ info->zoomfactor;
	info->start_y = yy + (info->start_y - yy) + (arrow.down - arrow.up)
		/ info->zoomfactor;
	info->end_y = yy + (info->end_y - yy) + (arrow.down - arrow.up)
		/ info->zoomfactor;
	info->end_x = xx + (info->end_x - xx) + (arrow.right - arrow.left)
		/ info->zoomfactor;
	ft_check_argv(info);
}

void	ft_arrowinit(t_arrow *arrow)
{
	arrow->down = 0;
	arrow->up = 0;
	arrow->left = 0;
	arrow->right = 0;
}

void	julia_press(t_info *info, int keysym)
{
	if (keysym == XK_x)
		info->c_real += 0.01 * info->sign;
	if (keysym == XK_y)
		info->c_imag += 0.01 * info->sign;
	ft_check_argv(info);
}

void	change_fractal(t_info *info, int keysym)
{
	if (keysym == XK_m)
		info->name = "Mandelbrot";
	if (keysym == XK_j)
		info->name = "Julia";
	if (keysym == XK_c)
		info->name = "Custom";
	backspace_press(info);
	ft_check_argv(info);
}
