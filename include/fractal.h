/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:09:53 by mregrag           #+#    #+#             */
/*   Updated: 2024/02/11 03:50:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../lib/MLX42.h"

# define WIDTH 800
# define HIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}			t_color;

typedef struct s_fractal
{
	mlx_t			*win;
	mlx_image_t		*img;
	char			*name;
	int				iteration;
	int				colors;
	double			move_x;
	double			move_y;
	double			zoom;
	double			julia_x;
	double			julia_y;
}				t_fractal;

t_complex	square_complex_buring(t_complex z);
t_complex	sum_complex_buring(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		my_keyhook(void	*param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
double		ft_atof(char *s);
double		map(double x, double a, double b, double max);
size_t		ft_strlen(const char *str);
void		mandelbrot(int x, int y, t_fractal *fractal);
void		julia(int x, int y, t_fractal *fractal);
void		draw_fractal(t_fractal *fractal);
void		burning(int x, int y, t_fractal *fractal);
void		check_fractal(int argc, char **argv, t_fractal *fractal);
void		ft_putendl_fd(const char *s, int fd);
int			ft_colors(t_fractal *fractal, int i);
int			ft_isdouble(char *str);
int			ft_error(char *s);

#endif