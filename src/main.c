/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vszpiech <vszpiech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:52:34 by vszpiech          #+#    #+#             */
/*   Updated: 2024/08/16 14:03:46 by vszpiech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	ft_clean_init(&f);
	ft_handle_errors(ac, av, &f);
	ft_init(&f);
	ft_render(&f);
	mlx_loop(f.mlx);
	free(f.mlx);
	return (0);
}
