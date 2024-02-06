/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:44:12 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/15 17:35:49 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ZOOMOUT 1.3
# define ZOOMIN 0.7
# define GRADIENT 10
# define MOVEMENT 0.2
# define HEIGHT 720
# define WIDTH	720
# define LENGTH 1080
# define MENU 850
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <math.h>	
# include "minilibx/mlx.h"
# include "libft/ft_printf/ft_printf.h"
# include "string.h"

typedef struct s_arrow
{
	float	up;
	float	down;
	float	left;
	float	right;
}	t_arrow;

typedef struct s_colorchange
{
	int	r;
	int	g;
	int	b;
	int	keysym;
}	t_colorchange;

typedef struct s_info
{
	void			*ptr;
	void			*win;
	void			*img;
	unsigned char	*ch;
	int				size_l;
	int				bpp;
	int				endian;
	double			start_x;
	double			end_x;
	double			start_y;
	double			end_y;
	double			x_o;
	double			y_o;
	int				zoom;
	float			zoomfactor;
	int				stop;
	int				max;
	int				color;
	t_colorchange	colorchange;
	char			*name;
	int				index;
	double			y_y;
	double			x_x;
	int				itier;
	double			x;
	double			y;
	double			xtmp;
	double			ytmp;
	double			c_real;
	double			c_imag;
	int				sign;
}	t_info;

//main
void	ft_init(t_info *info, char *str);
void	ft_check_argv(t_info *info);
void	ft_mlx_hook(t_info *info);

//menu
void	ft_string_put(t_info *t);
void	menu(t_info *t);

//utils
int		ft_strcmp(char *s1, char *s2);
void	ft_map(t_info *t);
void	ft_itier_loop(t_info *info);
void	ft_itier_loop2(t_info *info);
void	ft_itier_loop3(t_info *info);
void	ft_init_x_y(t_info *info);

//colors
void	ft_set_color(t_info *info, int color, t_colorchange colorchange);
void	ft_increase_red(t_info *info);
void	ft_increase_green(t_info *info);
void	ft_increase_blue(t_info *info);

//fractals
void	mandelbrot(t_info *info);
void	custom(t_info	*info);
void	julia(t_info *info);

//keypress
int		ft_handle_input(int keysym, t_info *info);
void	esc_press(t_info *info);
void	nbr_press(t_info *info, int keysym);
void	backspace_press(t_info *info);
void	c_press(t_info *info, int keysym);
void	arrow_press(t_info *info, int keysym);
void	ft_arrowinit(t_arrow *arrow);
void	julia_press(t_info *info, int keysym);
void	change_fractal(t_info *info, int keysym);

//mouse
int		ft_handle_mouse(int button, int x, int y, t_info *info);
void	ft_zoom(t_info *info, double x, double y, double zoom);
int		ft_x_button(t_info	*info);

#endif