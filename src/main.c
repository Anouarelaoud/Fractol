/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:06:04 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 19:07:31 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_display(t_mlx *p, char **argv)
{
	if (p)
		free(p);
	ft_putstr("\n\n\n\t\t\t!! Ce type est invalid \"");
	ft_putstr(argv[1]);
	ft_putstr("\" !!\n\n\n");
	ft_putstr("\t\t\tles types de Fractals disponibles : \n\n");
	ft_putstr("\t\t\t\t1 =====> Julia\n\t\t\t\t2 =====> Mandelbrot\n");
	ft_putstr("\t\t\t\t3 =====> Tricorne\n\t\t\t\t4 =====> Negatibrot\n");
	ft_putstr("\t\t\t\t5 =====> Quadcorne\n\t\t\t\t6 =====> Burningship\n");
	ft_putstr("\t\t\t\t7 =====> Parcial_cubic_i\n");
	ft_putstr("\t\t\t\t8 =====> Mandelbrot_cubic\n\n\n");
	exit(0);
}

void	ft_type_fract(t_mlx **p, char **argv)
{
	ft_initial(p);
	argv[1] = ft_strcapitalize(argv[1]);
	if (ft_strcmp("Mandelbrot", argv[1]) == 0)
		(*p)->type = 0;
	else if (ft_strcmp("Julia", argv[1]) == 0)
		(*p)->type = 1;
	else if (ft_strcmp("Tricorne", argv[1]) == 0)
		(*p)->type = 2;
	else if (ft_strcmp("Burningship", argv[1]) == 0)
		(*p)->type = 3;
	else if (ft_strcmp("Parcial_cubic_i", argv[1]) == 0)
		(*p)->type = 4;
	else if (ft_strcmp("Negatibrot", argv[1]) == 0)
		(*p)->type = 5;
	else if (ft_strcmp("Quadcorne", argv[1]) == 0)
		(*p)->type = 6;
	else if (ft_strcmp("Mandelbrot_cubic", argv[1]) == 0)
		(*p)->type = 7;
	else
		ft_display(*p, argv);
}

void	pal_col(t_mlx *p)
{
	p->color1 = ft_stock_colors("./colors/collor2");
	p->color2 = ft_stock_colors("./colors/collor1");
	p->color3 = ft_stock_colors("./colors/collor3");
	p->color4 = ft_stock_colors("./colors/collor4");
}

int		main(int argc, char **argv)
{
	t_mlx	*p;

	p = NULL;
	if (argc != 2)
	{
		ft_putstr("\n\n\t\t\tUsage : ./fractol [fractal_type]\n");
		ft_display(p, argv);
		exit(0);
	}
	ft_type_fract(&p, argv);
	pal_col(p);
	ft_creat_window(p);
	ft_menu(p);
	ft_creat_image(p);
	ft_draw(p);
	mlx_hook(p->win_ptr, 2, 0, ft_deal_key, p);
	mlx_hook(p->win_ptr, 6, 0, ft_mouse_move, p);
	mlx_hook(p->win_ptr, 4, 0, ft_mouse_press, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
