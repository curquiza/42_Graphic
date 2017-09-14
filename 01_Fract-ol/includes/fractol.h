/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:50:16 by curquiza          #+#    #+#             */
/*   Updated: 2017/08/23 18:52:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define TITLE "Fract'ol"
# define W 1000
# define H 800
# define MAX_ITER_JULIA 230
# define MAX_ITER_MANDEL 250
# define MAX_ITER_RABBIT 150
# define PALETTE_SIZE 256
# define COL_NB 7 * PALETTE_SIZE

typedef struct	s_point
{
	double	r;
	double	i;
}				t_point;

typedef struct	s_img
{
	void	*image;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef struct	s_tool
{
	void	*mlx;
	void	*win;
	int		type_fract;
	int		max_iter;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		move_julia;
	int		move_mandel;
	double	mouse_x;
	double	mouse_y;
	int		color_map[COL_NB];
	t_img	*img;
}				t_tool;

/*
** draw.c
*/
void			ft_put_pixtoimg(int col, t_img *img, int x, int y);
int				ft_rgb(int r, int g, int b);

/*
** init.c
*/
t_point			ft_newpoint(double x, double y);
t_img			*ft_set_img(t_tool *t);
t_tool			*ft_set_tool(int type_fract);
void			ft_init_fract(t_tool *t);

/*
** put_fract.c
*/
void			ft_put_fractal(t_tool *t);

/*
** event.c
*/
int				ft_event_key(int keycode, t_tool *t);
int				ft_event_mouse(int button, int x, int y, t_tool *t);
int				ft_mouse_pos(int x, int y, t_tool *t);

#endif
