/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:36:55 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 19:03:01 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_drawing_fract(t_thread *p, int b, int a)
{
	if (p->m->type == 0)
		ft_mlx_putpixel(p->m, b, a, ft_mandelbrot(p->m, b, a));
	else if (p->m->type == 1)
		ft_mlx_putpixel(p->m, b, a, ft_julia(p->m, b, a));
	else if (p->m->type == 2)
		ft_mlx_putpixel(p->m, b, a, ft_tricorne(p->m, b, a));
	else if (p->m->type == 3)
		ft_mlx_putpixel(p->m, b, a, ft_burningship(p->m, b, a));
	else if (p->m->type == 4)
		ft_mlx_putpixel(p->m, b, a, ft_parcial_cubic_i(p->m, b, a));
	else if (p->m->type == 5)
		ft_mlx_putpixel(p->m, b, a, ft_negatibrot(p->m, b, a));
	else if (p->m->type == 6)
		ft_mlx_putpixel(p->m, b, a, ft_quadcorne(p->m, b, a));
	else if (p->m->type == 7)
		ft_mlx_putpixel(p->m, b, a, ft_mandelbrot_cubic(p->m, b, a));
}

void	ft_write_img(t_thread *p)
{
	int			a;
	int			b;

	a = 0;
	while (a < (int)DIM)
	{
		b = (int)(p->i * DIM / NB_THREAD);
		while (b < (int)((p->i + 1) * DIM / NB_THREAD))
		{
			ft_drawing_fract(p, (long double)b, (long double)a);
			b++;
		}
		a++;
	}
}

char	*ft_detect_type(t_mlx *p)
{
	if (p->type == 0)
		return ("Mandelbrot");
	if (p->type == 1)
		return ("Julia");
	if (p->type == 2)
		return ("Tricorne");
	if (p->type == 3)
		return ("Burningship");
	if (p->type == 4)
		return ("Parcial_cubic_i ");
	if (p->type == 5)
		return ("Negatibrot");
	if (p->type == 6)
		return ("Quadcorne");
	if (p->type == 7)
		return ("Mandelbrot_cubic");
	return ("NO Fracts");
}

void	ft_draw(t_mlx *p)
{
	int			i;
	int			j;

	i = 0;
	ft_bzero(p->data, (int)DIM * (int)DIM * 4);
	ft_multi_thread(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 30);
	while (++i < DIM)
	{
		j = 0;
		while (++j < 30)
			mlx_pixel_put(p->mlx_ptr, p->win_ptr, i, j, 0x000000);
	}
	ft_header(p);
}

void	ft_multi_thread(t_mlx *p)
{
	pthread_t	thread[NB_THREAD];
	t_thread	tab[NB_THREAD];
	int			i;

	i = -1;
	while (++i < NB_THREAD)
	{
		tab[i].m = p;
		tab[i].i = i;
		pthread_create(&thread[i], NULL, (void*)ft_write_img, &tab[i]);
	}
	while (--i >= 0)
		pthread_join(thread[i], NULL);
}
