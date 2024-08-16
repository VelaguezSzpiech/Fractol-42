/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vszpiech <vszpiech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:52:23 by vszpiech          #+#    #+#             */
/*   Updated: 2024/08/16 14:14:06 by vszpiech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"



int	ft_key_events(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		ft_exit(EXIT_SUCCESS, f);
	else if (keycode == XK_Up || keycode == W)
		f->shift_y += (0.5 * f->zoom);
	else if (keycode == XK_Down || keycode == S)
		f->shift_y -= (0.5 * f->zoom);
	else if (keycode == XK_Left || keycode == A)
		f->shift_x -= (0.5 * f->zoom);
	else if (keycode == XK_Right || keycode == D)
		f->shift_x += (0.5 * f->zoom);
	else if (keycode == PLUS)
		f->iter += 10;
	else if (keycode == MINUS)
		f->iter -= 10;
	else if (keycode == SPACE)
	{
		f->space++;
	}
	ft_render(f);
	return (0);
}

int	ft_mouse_events(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (keycode == ZOOM_IN)
		f->zoom *= 0.95;
	else if (keycode == ZOOM_OUT)
		f->zoom *= 1.05;
	ft_render(f);
	return (0);
}
