/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fract_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:33:26 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 19:03:38 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_mandelbrot(t_mlx *p, long double col, long double row)
{
	int				i;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) * col) / DIM;
	c.im = p->y_min + ((p->y_max - p->y_min) / DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}

int		ft_julia(t_mlx *p, long double col, long double row)
{
	int				i;
	t_com			z;
	t_com			c;
	long double		tmp;

	z.re = p->x_min + ((p->x_max - p->x_min) / DIM) * col;
	z.im = p->y_min + ((p->y_max - p->y_min) / DIM) * row;
	c.re = p->jul_re;
	c.im = p->jul_im;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}

int		ft_tricorne(t_mlx *p, long double col, long double row)
{
	int				i;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = -1 * 2 * tmp * z.im + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}

int		ft_mandelbrot_cubic(t_mlx *p, long double col, long double row)
{
	int				i;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < p->prof_max)
	{
		tmp = z.re;
		z.re = ((3 * z.re * z.re) - (z.im * z.im)) * z.im + c.re;
		z.im = ((z.re * z.re) - (3 * z.im * z.im)) * z.im + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}
