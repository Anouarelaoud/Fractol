/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:29:55 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 18:56:45 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_detect_move(t_mlx *p, int key)
{
	if (key == KEY_LEFT)
	{
		p->x_min += 0.2 * p->speed;
		p->x_max += 0.2 * p->speed;
	}
	if (key == KEY_RIGHT)
	{
		p->x_min -= 0.2 * p->speed;
		p->x_max -= 0.2 * p->speed;
	}
	if (key == KEY_DOWN)
	{
		p->y_min -= 0.2 * p->speed;
		p->y_max -= 0.2 * p->speed;
	}
	if (key == KEY_UP)
	{
		p->y_min += 0.2 * p->speed;
		p->y_max += 0.2 * p->speed;
	}
}

void	ft_detect_events(t_mlx *p, int key)
{
	if (key == KEY_P)
		p->pause = (p->pause + 1) % 2;
	if (key == KEY_ENTRER)
	{
		ft_reinitialise(p);
		p->type = (p->type + 1) % 8;
	}
	if (key == KEY_SPACE)
		p->col_type = (p->col_type + 1) % 4;
	if (key == KEY_R)
		ft_reinitialise(p);
	if (key == KEY_W)
		p->prof_max++;
	if (key == KEY_S)
		p->prof_max--;
}

int		ft_deal_key(int key, t_mlx *p)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(p->mlx_ptr, p->img_ptr);
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		free(p->size);
		free(p->endian);
		free(p->bpp);
		free(p);
		exit(0);
	}
	if (key == KEY_PLUS)
	{
		ft_zoom(p, DIM / 2.0, (DIM + 60) / 2.0, 0.8);
		p->speed *= 0.8;
	}
	if (key == KEY_MINUS)
	{
		ft_zoom(p, DIM / 2.0, DIM / 2.0, 1.0 / 0.8);
		p->speed *= 1.0 / 0.8;
	}
	ft_detect_events(p, key);
	ft_detect_move(p, key);
	ft_draw(p);
	return (key);
}

int		ft_mouse_move(int x, int y, t_mlx *p)
{
	if (p->pause == 0 && p->type == 1)
	{
		p->jul_re = (x - DIM / 2) / DIM;
		p->jul_im = (y - DIM / 2) / DIM;
	}
	ft_draw(p);
	return (0);
}

int		ft_mouse_press(int button, int x, int y, t_mlx *p)
{
	if (button == 5)
	{
		ft_zoom(p, x, y, 0.8);
		p->speed *= 0.8;
	}
	else if (button == 4)
	{
		ft_zoom(p, x, y, 1.0 / 0.8);
		p->speed *= 1.0 / 0.8;
	}
	ft_draw(p);
	return (button);
}
