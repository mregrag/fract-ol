/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:44:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 01:27:57 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = 0;
	c.x = (map(x, -2, +2, WIDTH) * fractal->zoom);
	c.y = (map(y, +2, -2, HIGHT) * fractal->zoom);
	z.x = 0;
	z.y = 0;
	while ((z.x * z.x) + (z.y * z.y) <= 4 && i < fractal->iteration)
	{
		z = sum_complex(square_complex(z), c);
		i++;
	}
	color = ft_colors(fractal, i);
	if (i == fractal->iteration)
		mlx_put_pixel(fractal->img, x, y, 0x0000FF);
	else
		mlx_put_pixel(fractal->img, x, y, color);
}
