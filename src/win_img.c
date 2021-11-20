/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:12:16 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 14:47:27 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_mlx_putpixel(t_mlx *p, int x, int y, int color)
{
	if ((x >= 0 && x < DIM) && y >= 0 && y < DIM)
		p->data[y * (int)DIM + x] = color;
}

void	ft_creat_window(t_mlx *p)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, DIM, DIM + 100, "fract'ol");
}

void	ft_creat_image(t_mlx *p)
{
	p->img_ptr = mlx_new_image(p->mlx_ptr, DIM, DIM);
	p->data = (int*)mlx_get_data_addr(p->img_ptr, p->bpp, p->size, p->endian);
}

void	ft_header(t_mlx *p)
{
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 1, 0x4FC3F7,
			"<Number_of_iterations> : ");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 250, 1, 0xFF6B2C,
			ft_itoa(p->prof_max));
	mlx_string_put(p->mlx_ptr, p->win_ptr, 460, 2, 0x4FC3F7,
			"<Fractal_type> :");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 630, 2, 0xFF6B2C,
			ft_detect_type(p));
}

void	ft_menu(t_mlx *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < DIM)
	{
		j = 0;
		while (j < 30)
		{
			mlx_pixel_put(p->mlx_ptr, p->win_ptr, i, j, 0x000000);
			j++;
		}
		i++;
	}
	mlx_string_put(p->mlx_ptr, p->win_ptr, 350, DIM + 35, 0x4FC3F7,
			"OPTIONS");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 7, DIM + 66, 0x4FC3F7,
			"ENTRER:Type/ P:Pause-Play/ R:Reset/ ESPACE:Colors");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 495, DIM + 66, 0x4FC3F7,
			"/ W-S:Inc-Dec iter/ (+/-):zoom");
}
