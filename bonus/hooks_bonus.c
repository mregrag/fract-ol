/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:42:08 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 07:07:11 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	my_keyhook(void	*param)
{
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->win, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->win);
	if (mlx_is_key_down(fractal->win, MLX_KEY_LEFT))
		fractal->move_x += (0.2 * fractal->zoom);
	if (mlx_is_key_down(fractal->win, MLX_KEY_RIGHT))
		fractal->move_x -= (0.2 * fractal->zoom);
	if (mlx_is_key_down(fractal->win, MLX_KEY_UP))
		fractal->move_y -= (0.2 * fractal->zoom);
	if (mlx_is_key_down(fractal->win, MLX_KEY_DOWN))
		fractal->move_y += (0.2 * fractal->zoom);
	if (mlx_is_key_down(fractal->win, MLX_KEY_KP_ADD))
		fractal->iteration += 1;
	if (mlx_is_key_down(fractal->win, MLX_KEY_KP_SUBTRACT))
	{
		if (fractal->iteration > 21)
			fractal->iteration -= 1;
	}
	if (mlx_is_key_down(fractal->win, MLX_KEY_SPACE))
		fractal->colors += 2;
	draw_fractal(fractal);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	int32_t		x;
	int32_t		y;

	fractal = param;
	mlx_get_mouse_pos(fractal->win, &x, &y);
	xdelta = 0;
	if (ydelta > 0)
		fractal->zoom *= 0.95;
	else if (ydelta < 0)
		fractal->zoom *= 1.05;
}
