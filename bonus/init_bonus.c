/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:08:52 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 23:24:38 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	data_init(t_fractal *fractal)
{
	fractal->iteration = 62;
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
	fractal->zoom = 1.0;
	fractal->colors = 1;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->win = mlx_init(WIDTH, HIGHT, fractal->name, false);
	if (!fractal->win)
	{
		exit (EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->win, WIDTH, HIGHT);
	if (!fractal->img)
	{
		mlx_close_window(fractal->win);
		exit (EXIT_FAILURE);
	}
}
