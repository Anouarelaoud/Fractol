/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fract_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:11:41 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 19:03:49 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_burningship(t_mlx *p, long double col, long double row)
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
		if (tmp < 0)
			tmp *= -1.0;
		if (z.im < 0)
			z.im *= -1.0;
		z.im = 2 * (tmp) * (z.im) + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}

int		ft_quadcorne(t_mlx *p, long double col, long double row)
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
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}

int		ft_negatibrot(t_mlx *p, long double col, long double row)
{
	int				i;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / DIM) * row;
	z.re = c.re;
	z.im = c.im;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < p->prof_max)
	{
		tmp = z.re;
		z.re = (z.re * z.re - z.im * z.im) / (z.re * z.re * z.re * z.re
				+ z.im * z.im * z.im * z.im + 2 * z.re * z.re * z.im * z.im)
			+ c.re;
		z.im = -(2 * tmp * z.im) / (tmp * tmp * tmp * tmp + z.im * z.im *
				z.im * z.im + 2 * tmp * tmp * z.im * z.im) + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}

int		ft_parcial_cubic_i(t_mlx *p, long double col, long double row)
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
		if (z.re < 0)
			z.re *= -1;
		tmp = z.re;
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		i++;
	}
	return (ft_get_color(p, i));
}
