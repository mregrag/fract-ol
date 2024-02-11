/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:46:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/09 19:07:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

double	map(double x, double a, double b, double max)
{
	return ((b - a) * (x / max) + a);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2.0 * z.x * z.y;
	return (result);
}

t_complex	sum_complex_buring(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = fabs(z1.x + z2.x);
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex_buring(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = fabs(2.0 * z.x * z.y);
	return (result);
}
