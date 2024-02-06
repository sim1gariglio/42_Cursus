/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:18:21 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:10:46 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_input(int keysym, t_info *info)
{
	if (keysym == XK_equal)
		info->sign = 1;
	if (keysym == XK_minus)
		info->sign = -1;
	if (keysym == XK_Escape)
		esc_press(info);
	if (keysym >= XK_0 && keysym <= XK_9)
		nbr_press(info, keysym);
	if (keysym == XK_BackSpace)
		backspace_press(info);
	if (keysym == XK_b || keysym == XK_g || keysym == XK_r)
		c_press(info, keysym);
	if (keysym == XK_Down || keysym == XK_Up
		|| keysym == XK_Left || keysym == XK_Right)
		arrow_press(info, keysym);
	if (keysym == XK_x || keysym == XK_y)
		julia_press(info, keysym);
	if (keysym == XK_m || keysym == XK_j || keysym == XK_c)
		change_fractal(info, keysym);
	return (0);
}

void	esc_press(t_info *info)
{
	ft_printf("Exiting program\n");
	mlx_destroy_image(info->ptr, info->img);
	mlx_destroy_window(info->ptr, info->win);
	mlx_destroy_display(info->ptr);
	free(info->ptr);
	exit(1);
}

void	nbr_press(t_info *info, int keysym)
{
	info->colorchange.keysym = keysym * keysym;
	if (keysym == XK_0)
		info->colorchange.keysym = 1;
	if (info->itier == info->max)
		ft_set_color(info, 0, info->colorchange);
	else
		ft_set_color(info, 1, info->colorchange);
	ft_printf("Changing color to %d\n", keysym - 48);
	ft_check_argv(info);
}

void	backspace_press(t_info *info)
{
	ft_init(info, info->name);
	ft_printf("Resetting view\n");
	ft_check_argv(info);
}

void	c_press(t_info *info, int keysym)
{
	if (keysym == XK_r)
		ft_increase_red(info);
	else if (keysym == XK_g)
		ft_increase_green(info);
	else if (keysym == XK_b)
		ft_increase_blue(info);
	ft_check_argv(info);
}
