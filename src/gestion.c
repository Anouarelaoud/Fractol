/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:24:55 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 19:03:13 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_initial(t_mlx **p)
{
	(*p) = (struct s_mlx *)malloc(sizeof(struct s_mlx));
	(*p)->bpp = (int *)malloc(4);
	(*p)->size = (int *)malloc(4);
	(*p)->endian = (int *)malloc(4);
	(*p)->mlx_ptr = NULL;
	(*p)->img_ptr = NULL;
	(*p)->win_ptr = NULL;
	(*p)->data = NULL;
	(*p)->zoom = 1.0;
	(*p)->y_max = 2.0;
	(*p)->x_max = 2.0;
	(*p)->x_min = -2.0;
	(*p)->y_min = -2.0;
	(*p)->jul_re = 0.0;
	(*p)->jul_im = 0.0;
	(*p)->pause = 0;
	(*p)->speed = 0.8;
	(*p)->prof_max = MAX_ITER;
	(*p)->col_type = 0;
}

void	ft_reinitialise(t_mlx *p)
{
	p->speed = 0.8;
	p->prof_max = MAX_ITER;
	p->y_max = 2.0;
	p->x_max = 2.0;
	p->x_min = -2.0;
	p->y_min = -2.0;
}

void	ft_zoom(t_mlx *p, long double x, long double y, long double k)
{
	long double		x1;
	long double		y1;

	x1 = (x / DIM) * (p->x_max - p->x_min) + p->x_min;
	y1 = ((y - 30) / DIM) * (p->y_max - p->y_min) + p->y_min;
	p->x_min = x1 + ((p->x_min - x1) * k);
	p->y_min = y1 + ((p->y_min - y1) * k);
	p->x_max = x1 + ((p->x_max - x1) * k);
	p->y_max = y1 + ((p->y_max - y1) * k);
}

int		*ft_stock_colors(char *file)
{
	int		i;
	int		fd;
	int		*collor;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	collor = (int *)malloc(sizeof(int) * 100);
	while (get_next_line(fd, &line))
	{
		collor[i] = ft_atoi_base(line, 16);
		free(line);
		i++;
	}
	return (collor);
}

int		ft_get_color(t_mlx *p, int nb_i)
{
	int		i;

	i = nb_i % 100;
	if (nb_i == MAX_ITER)
		return (0);
	if (p->col_type == 0)
		return (p->color1[i]);
	if (p->col_type == 1)
		return (p->color2[i]);
	if (p->col_type == 2)
		return (p->color3[i]);
	if (p->col_type == 3)
		return (p->color4[i]);
	return (0);
}
