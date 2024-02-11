/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:17:21 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 21:18:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	ft_colors(t_fractal *fractal, int i)
{
	t_color		rgb;	

	(void)fractal;
	rgb.r = (i * 2) % 256;
	rgb.g = (i * 8) % 256;
	rgb.b = (i * 2) % 256;
	return (rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 255);
}
