/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:58:28 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:35:29 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_info *t)
{
	int		i;
	int		j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = HEIGHT;
		while (++i < LENGTH)
		{
			t->index = (j * LENGTH * 4) + (i * 4);
			t->ch[t->index] = 0;
			t->ch[t->index + 1] = 0;
			t->ch[t->index + 2] = 0;
			t->ch[t->index + 3] = 0;
		}
	}
	mlx_put_image_to_window(t->ptr, t->win, t->img, 0, 0);
	ft_string_put(t);
}

void	ft_string_put(t_info *t)
{
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (0.5 / 4.0)), 0xf7b079,
		"THIS IS A MENU");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (0.8 / 4.0)), 0xf7b079,
		"Mandelbrot: <M>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (1.0 / 4.0)), 0xf7b079,
		"Julia: <J>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (1.2 / 4.0)), 0xf7b079,
		"Custom: <C>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (1.5 / 4.0)), 0xf7b079,
		"RESET VIEW: <Backspace>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (1.7 / 4.0)), 0xf7b079,
		"Modify Custom or Julia: <x/y> <+/->");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (1.9 / 4.0)), 0xf7b079,
		"Zoom: <Wheel up/down>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (2.1 / 4.0)), 0xf7b079,
		"Move visual: <arrows>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (2.3 / 4.0)), 0xf7b079,
		"Random colors: <0-9>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (2.5 / 4.0)), 0xf7b079,
		"Increase red component: <R>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (2.7 / 4.0)), 0xf7b079,
		"Increase green component: <G>");
	mlx_string_put(t->ptr, t->win, MENU, (HEIGHT * (2.9 / 4.0)), 0xf7b079,
		"Increase blue component: <B>");
}
