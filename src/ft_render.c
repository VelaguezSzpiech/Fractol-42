/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vszpiech <vszpiech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:48:38 by vszpiech          #+#    #+#             */
/*   Updated: 2024/08/16 14:03:33 by vszpiech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_put_pixel(int x, int y, t_img *img, int color)
{
	unsigned int	*pixel;

	pixel = (unsigned int *)(img->pixels + (y * img->line_len)
			+ (x * (img->bpp / 8)));
	*pixel = color;
}

static inline void	ft_set_fractal(t_complex *z, t_complex *c, t_fractol *f)
{
	if (f->set == JULIA)
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
		*c = *z;
}

static inline int	ft_get_color(int iter, int max_iter)
{
	int	intensity;

	intensity = (int)(255.0 * ((double)iter / max_iter));
	return ((intensity << 16) | (intensity << 8) | intensity);
}

void	ft_handle_pixel(t_pixel_data *p, t_fractol *f)
{
	t_calc_data	data;	

	data.zx = (ft_map(p->x, -2, 2, WIDTH) * p->zoom) + p->shift_x;
	data.zy = (ft_map(p->y, 2, -2, HEIGHT) * p->zoom) + p->shift_y;
	data.zx2 = data.zx * data.zx;
	data.zy2 = data.zy * data.zy;
	data.i = 0;
	ft_set_fractal(&(t_complex){data.zx, data.zy}, &data.c, f);
	while (data.i < f->iter && (data.zx2 + data.zy2) <= f->escape_val)
	{
		data.zy = 2 * data.zx * data.zy + data.c.y;
		data.zx = data.zx2 - data.zy2 + data.c.x;
		data.zx2 = data.zx * data.zx;
		data.zy2 = data.zy * data.zy;
		data.i++;
	}
	if (data.i < f->iter)
		ft_put_pixel(p->x, p->y, &f->img, ft_get_color(data.i, f->iter));
	else
		ft_put_pixel(p->x, p->y, &f->img, f->color);
}

void	ft_render(t_fractol *f)
{
	int				x;
	int				y;
	t_pixel_data	p;

	p.zoom = f->zoom;
	p.shift_x = f->shift_x;
	p.shift_y = f->shift_y;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			p.x = x;
			p.y = y;
			ft_handle_pixel(&p, f);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img.img_ptr, 0, 0);
}
