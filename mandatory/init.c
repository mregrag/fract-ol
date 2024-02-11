/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:08:52 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 23:19:32 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	data_init(t_fractal *fractal)
{
	fractal->iteration = 62;
	fractal->zoom = 1.0;
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
