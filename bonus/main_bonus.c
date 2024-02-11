/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:46:27 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 23:23:30 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	check_fractal(argc, argv, &fractal);
	fractal_init(&fractal);
	data_init(&fractal);
	mlx_loop_hook(fractal.win, my_keyhook, &fractal);
	mlx_scroll_hook(fractal.win, my_scrollhook, &fractal);
	mlx_loop(fractal.win);
	mlx_terminate(fractal.win);
	exit(EXIT_SUCCESS);
}
