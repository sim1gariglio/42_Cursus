/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:53:23 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:33:53 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map(t_info *info)
{
	info->x = (info->x_x
			/ (WIDTH / (info->end_x - info->start_x))) + info->start_x;
	info->y = (info->y_y
			/ (HEIGHT / (info->end_y - info->start_y))) + info->start_y;
	info->x_o = info->x;
	info->y_o = info->y;
}

void	ft_init_x_y(t_info *info)
{
	info->x = ((info->x_x / (double)HEIGHT)
			* (info->end_x - info->start_x)) + info->start_x;
	info->y = ((info->y_y / (double)WIDTH)
			* (info->end_y - info->start_y)) + info->start_y;
}

void	ft_itier_loop(t_info *info)
{
	while (info->itier < info->max)
	{
		info->xtmp = info->x * info->x - info->y * info->y;
		info->ytmp = 2 * info->x * info->y;
		info->x = info->xtmp + info->x_o;
		info->y = info->ytmp + info->y_o;
		if (info->x * info->x + info->y * info->y > 4)
			break ;
		info->itier++;
	}
}

void	ft_itier_loop2(t_info *info)
{
	while (info->itier < info->max)
	{
		info->xtmp = info->x * info->x - info->y * info->y;
		info->ytmp = 2 * info->x * info->y;
		info->x = info->xtmp;
		info->y = info->ytmp;
		info->x += info->c_real;
		info->y += info->c_imag;
		if (info->x * info->x + info->y * info->y > 4)
			break ;
		info->itier++;
	}
}

void	ft_itier_loop3(t_info *info)
{
	while (info->itier < info->max)
	{
		info->xtmp = (info->x * info->x - info->y * info->y) * 2;
		info->ytmp = info->x * info->y * 3;
		info->x = info->xtmp;
		info->y = info->ytmp;
		info->x += info->c_real;
		info->y += info->c_imag;
		if (info->x * info->x + info->y * info->y > 4)
			break ;
		info->itier++;
	}
}
