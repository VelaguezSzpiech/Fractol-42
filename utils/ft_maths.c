/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vszpiech <vszpiech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:08:29 by vszpiech          #+#    #+#             */
/*   Updated: 2024/08/14 16:09:40 by vszpiech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double ft_map(double n, double n_min, double n_max, double o_max)
{
    return ((n_max - n_min) * n / o_max + n_min);
}

t_complex ft_sum(t_complex z1, t_complex z2)
{
    return (t_complex){z1.x + z2.x, z1.y + z2.y};
}

t_complex ft_square(t_complex z)
{
    return (t_complex){(z.x * z.x) - (z.y * z.y), 2 * z.x * z.y};
}