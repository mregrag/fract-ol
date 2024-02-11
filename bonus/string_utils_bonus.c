/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:21:36 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/10 23:49:39 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	ft_isdouble(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	if (*str == 45 || *str == 43)
		str++;
	while (*str)
	{
		if ((*str >= 48 && *str <= 57) || *str == 46)
		{
			if (*str == 46)
				count++;
			if (count > 1)
				return (0);
			str++;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_putendl_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

double	ft_atof(char *str)
{
	double	nb;
	int		decimal;
	int		sign;

	if (!str)
		return (0);
	nb = 0;
	sign = 1;
	decimal = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
		if (*str++ == 45)
			sign *= -1;
	while (*str >= 48 && *str <= 57)
		nb = (nb * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb = (nb * 10) + (*str++ - 48);
		decimal = decimal * 10;
	}
	return (nb / decimal * sign);
}
