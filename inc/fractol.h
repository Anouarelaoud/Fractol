/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:49:52 by aait-el-          #+#    #+#             */
/*   Updated: 2019/07/24 19:33:44 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define KEY_ESC 53
# define KEY_MINUS 78
# define KEY_PLUS 69
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_P 35
# define KEY_I 34
# define KEY_SPACE 49
# define KEY_W 13
# define KEY_S 1
# define KEY_ENTRER 36
# define KEY_R 15
# define DIM 800.0
# define MAX_ITER 30
# define NB_THREAD 4

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			*bpp;
	int			*size;
	int			*endian;
	int			type;
	long double	x_max;
	long double	x_min;
	long double	y_max;
	long double	y_min;
	long double	zoom;
	long double	jul_re;
	long double	jul_im;
	long double	speed;
	int			pause;
	int			prof_max;
	int			col_type;
	int			*color1;
	int			*color2;
	int			*color3;
	int			*color4;
}				t_mlx;

typedef struct	s_thread
{
	int			i;
	t_mlx		*m;
}				t_thread;

typedef struct	s_com
{
	long double	im;
	long double	re;
}				t_com;

int				ft_get_color(t_mlx *p, int nb_i);
int				*ft_stock_colors(char *file);
int				ft_atoi_base(char *str, int base);
int				test_base(char c);
int				get_next_line(int fd, char **line);
void			ft_detect_move(t_mlx *p, int key);
void			ft_detect_events(t_mlx *p, int key);
int				ft_deal_key(int key, t_mlx *p);
int				ft_mouse_move(int x, int y, t_mlx *p);
int				ft_mouse_press(int button, int x, int y, t_mlx *p);
int				ft_mandelbrot(t_mlx *p, long double col, long double row);
int				ft_julia(t_mlx *p, long double col, long double row);
int				ft_tricorne(t_mlx *p, long double col, long double row);
int				ft_burningship(t_mlx *p, long double col, long double row);
int				ft_quadcorne(t_mlx *p, long double col, long double row);
int				ft_negatibrot(t_mlx *p, long double col, long double row);
int				ft_parcial_cubic_i(t_mlx *p, long double col, long double row);
int				ft_mandelbrot_cubic(t_mlx *p, long double col, long double row);
void			ft_write_img(t_thread *p);
void			ft_mlx_putpixel(t_mlx *p, int x, int y, int color);
void			ft_creat_window(t_mlx *p);
void			ft_creat_image(t_mlx *p);
void			ft_type_fract(t_mlx **p, char **argv);
char			*ft_detect_type(t_mlx *p);
void			ft_drawing_fract(t_thread *p, int b, int a);
void			ft_draw(t_mlx *p);
void			ft_zoom(t_mlx *p, long double x, long double y, long double k);
void			ft_initial(t_mlx **p);
void			ft_display(t_mlx *p, char **argv);
void			ft_menu(t_mlx *p);
void			ft_header(t_mlx *p);
void			ft_reinitialise(t_mlx *p);
void			ft_multi_thread(t_mlx *p);
void			ft1(char **str1, char **aux, char str2[5], int nbr_oct);
void			ft2(char **line, char **str1, char **aux, int i);

#endif
