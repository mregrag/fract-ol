/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:49:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/09 20:42:24 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	burning(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = 0;
	c.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->move_x;
	c.y = (map(y, -2, +2, HIGHT) * fractal->zoom) + fractal->move_y;
	z.x = 0.0;
	z.y = 0.0;
	while ((z.x * z.x) + (z.y * z.y) <= 4 && i < fractal->iteration)
	{
		z = sum_complex_buring(square_complex_buring(z), c);
		i++;
	}
	color = ft_colors(fractal, i);
	if (i == fractal->iteration)
		mlx_put_pixel(fractal->img, x, y, 0x0000FF);
	else
		mlx_put_pixel(fractal->img, x, y, color);
}
