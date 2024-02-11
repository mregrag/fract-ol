/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:17:21 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 20:29:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	ft_colors(t_fractal *fractal, int i)
{
	t_color	rgb;

	rgb.r = ((i * fractal->colors) * 2) % 256;
	rgb.g = ((i * fractal->colors) * 8) % 256;
	rgb.b = ((i * fractal->colors) * 2) % 256;
	return (rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 255);
}
