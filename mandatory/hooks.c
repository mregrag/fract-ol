/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:42:08 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 22:03:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	my_keyhook(void	*param)
{
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->win, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->win);
	if (mlx_is_key_down(fractal->win, MLX_KEY_KP_ADD))
		fractal->iteration += 1;
	if (mlx_is_key_down(fractal->win, MLX_KEY_KP_SUBTRACT))
	{
		if (fractal->iteration > 21)
			fractal->iteration -= 1;
	}
	draw_fractal(fractal);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	xdelta = 0;
	if (ydelta > 0)
		fractal->zoom *= 0.95;
	else if (ydelta < 0)
		fractal->zoom *= 1.05;
}
