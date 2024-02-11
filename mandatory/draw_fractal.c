/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:52:54 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/11 02:47:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static	void	draw_mandelbrot(t_fractal *fractal)
{
	uint32_t	x;
	uint32_t	y;

	x = -1;
	while (++x < fractal->img->width)
	{
		y = -1;
		while (++y < fractal->img->height)
			mandelbrot(x, y, fractal);
	}
	if (mlx_image_to_window(fractal->win, fractal->img, 0, 0) == -1)
	{
		mlx_close_window(fractal->win);
		exit(EXIT_FAILURE);
	}
}

static	void	draw_julia(t_fractal *fractal)
{
	uint32_t	x;
	uint32_t	y;

	x = -1;
	while (++x < fractal->img->width)
	{
		y = -1;
		while (++y < fractal->img->height)
			julia(x, y, fractal);
	}
	if (mlx_image_to_window(fractal->win, fractal->img, 0, 0) == -1)
	{
		mlx_close_window(fractal->win);
		exit(EXIT_FAILURE);
	}
}

void	draw_fractal(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 6))
		draw_julia(fractal);
}
