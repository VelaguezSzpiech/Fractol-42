/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:MM by username         #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:MM by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "events.h"
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2
# define HEIGHT 1000
# define WIDTH 1000

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_pixel_data
{
	int			x;
	int			y;
	double		zoom;
	double		shift_x;
	double		shift_y;
}				t_pixel_data;

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;
typedef struct s_calc_data
{
	double		zx;
	double		zy;
	double		zx2;
	double		zy2;
	int			i;
	t_complex	c;
}				t_calc_data;

typedef struct s_fractol
{
	t_img		img;
	void		*mlx;
	void		*window;
	char		*name;
	int			set;
	int			iter;
	int			color;
	int			space;
	double		escape_val;
	double		shift_x;
	double		shift_y;
	double		julia_x;
	double		julia_y;
	double		zoom;
	int			color_r;
	int			color_g;
	int			color_b;
}				t_fractol;
void		ft_handle_errors(int ac, char **av, t_fractol *f);
void		ft_msg(t_fractol *f);
void		ft_msg_julia(t_fractol *f);
void		ft_julia(char **av, int ac, t_fractol *f);
int			ft_check_values(double nb1, double nb2);
void		ft_init(t_fractol *f);
void		ft_clean_init(t_fractol *f);
void		ft_init_events(t_fractol *f);
void		ft_render(t_fractol *f);
void		ft_handle_pixel(t_pixel_data *p, t_fractol *f);
void		ft_put_pixel(int x, int y, t_img *img, int color);
int			ft_key_events(int keycode, t_fractol *mlx);
int			ft_mouse_events(int keycode, int x, int y, t_fractol *f);
void		ft_exit(int code, t_fractol *f);
int			ft_clean_exit(t_fractol *f);
double		ft_map(double n, double n_min, double n_max, double o_max);
t_complex	ft_sum(t_complex z1, t_complex z2);
t_complex	ft_square(t_complex z);

#endif
