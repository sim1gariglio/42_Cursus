/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:53:48 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/16 11:27:56 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*news1;
	unsigned char	*news2;

	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	i = 0;
	while (news1[i] != 0 || news2[i] != 0)
	{
		if (news1[i] != news2[i])
			return (news1[i] - news2[i]);
		i++;
	}
	return (news1[i] - news2[i]);
}

void	ft_init(t_info *info, char *str)
{
	info->start_x = -2.0;
	info->end_x = 1.0;
	info->start_y = -1.5;
	info->end_y = 1.5;
	info->x_o = -0.75;
	info->y_o = 0.0;
	info->zoom = 0;
	info->stop = 0;
	info->max = 100;
	info->color = 10;
	info->colorchange.keysym = XK_1;
	info->colorchange.g = 0;
	info->colorchange.r = 0;
	info->colorchange.b = 0;
	info->name = str;
	info->zoomfactor = 1;
	info->c_real = -0.7;
	info->c_imag = 0.27015;
	info->sign = 1;
}

void	ft_mlx_hook(t_info *info)
{
	menu(info);
	mlx_mouse_hook(info->win, ft_handle_mouse, info);
	mlx_key_hook(info->win, ft_handle_input, info);
	mlx_loop(info->ptr);
}

void	ft_check_argv(t_info *info)
{
	if (ft_strcmp(info->name, "Mandelbrot") == 0)
		mandelbrot(info);
	else if (ft_strcmp(info->name, "Custom") == 0)
		custom(info);
	else if (ft_strcmp(info->name, "Julia") == 0)
		julia(info);
	else
	{
		ft_printf("Scrivi bene scemo\n%s\n", info->name);
		mlx_destroy_image(info->ptr, info->img);
		mlx_destroy_window(info->ptr, info->win);
		mlx_destroy_display(info->ptr);
		free(info->ptr);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if ((argc == 2 && (ft_strcmp(argv[1], "Mandelbrot") == 0
				|| ft_strcmp(argv[1], "Custom") == 0
				|| ft_strcmp(argv[1], "Julia") == 0))
		|| ((argc == 3 || argc == 4) && ft_strcmp(argv[1], "Julia") == 0))
	{
		info.ptr = mlx_init();
		info.win = mlx_new_window(info.ptr, LENGTH, HEIGHT, "Fractol");
		info.img = mlx_new_image(info.ptr, LENGTH, HEIGHT);
		info.ch = (unsigned char *)
			mlx_get_data_addr(info.img, &info.bpp, &info.size_l, &info.endian);
		ft_init(&info, argv[1]);
		if (argc >= 3)
			info.c_real = ft_atoi(argv[2]);
		if (argc == 4)
			info.c_imag = ft_atoi(argv[3]);
		mlx_hook(info.win, 33, 1L << 5, ft_x_button, &info);
		ft_check_argv(&info);
	}
	else
		ft_printf("Ecco i frattali disponibili: |Mandelbrot|Julia|Custom|\n");
	return (0);
}
