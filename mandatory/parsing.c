/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:20:39 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/11 02:48:08 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static	void	check_julia(t_fractal *fractal, char **argv, int argc)
{
	if (argc < 4)
		ft_error("Invalid Julia argument");
	if (!ft_isdouble(argv[2]) && !ft_isdouble(argv[3]))
		ft_error("Invalid Julia, Invalid constant real and imaginary");
	if ((ft_atof(argv[2]) > 2) || (ft_atof(argv[2]) < -2))
		ft_error("Invalid Julia, Invalid constant real");
	else if (!ft_isdouble(argv[2]))
		ft_error("Invalid Julia, Invalid constant real");
	if ((ft_atof(argv[3]) > 2) || (ft_atof(argv[3]) < -2))
		ft_error("Invalid Julia, Invalid constant imaginary.");
	else if (!ft_isdouble(argv[3]))
		ft_error("Invalid Julia, Invalid constant imaginary");
	else
	{
		fractal->name = argv[1];
		fractal->julia_x = ft_atof(argv[2]);
		fractal->julia_y = ft_atof(argv[3]);
	}
}

static	void	check_mandelbrot(t_fractal *fractal, char **argv, int argc)
{
	if (argc > 2)
		ft_error("Invalid Mandelbrot, Too many argument");
	else
		fractal->name = argv[1];
}

void	check_fractal(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2 || argc > 4)
		ft_error("Invalid Fractal");
	if (!ft_strncmp(argv[1], "julia", 6))
		check_julia(fractal, argv, argc);
	else if (!ft_strncmp(argv[1], "mandelbrot", 11))
		check_mandelbrot(fractal, argv, argc);
	else
		ft_error("Avialable fractal: mandelbrot, julia");
}
