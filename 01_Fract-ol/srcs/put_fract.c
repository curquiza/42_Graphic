/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fract.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:50:16 by curquiza          #+#    #+#             */
/*   Updated: 2017/08/23 18:52:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pix_julia(t_tool *t, int x, int y)
{
	t_point	z;
	t_point	c;
	t_point	tmp;
	int		i;

	z = ft_newpoint((double)x / ((double)W / (t->x2 - t->x1)) + t->x1,
					(double)y / ((double)H / (t->y2 - t->y1)) + t->y1);
	c = ft_newpoint(t->mouse_x, t->mouse_y);
	tmp = ft_newpoint(0, 0);
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < t->max_iter)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2.0 * tmp.r * tmp.i + c.i;
		i++;
	}
	if (i == t->max_iter)
		ft_put_pixtoimg(0, t->img, x, y);
	else
		ft_put_pixtoimg(t->color_map[i * (COL_NB - 1) / t->max_iter],
						t->img, x, y);
}

void	ft_pix_mandelbrot(t_tool *t, int x, int y)
{
	t_point	z;
	t_point	c;
	t_point	tmp;
	int		i;

	z = ft_newpoint(t->mouse_x, t->mouse_y);
	c = ft_newpoint((double)x / ((double)W / (t->x2 - t->x1)) + t->x1,
					(double)y / ((double)H / (t->y2 - t->y1)) + t->y1);
	tmp = ft_newpoint(0, 0);
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < t->max_iter)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2.0 * tmp.r * tmp.i + c.i;
		i++;
	}
	if (i == t->max_iter)
		ft_put_pixtoimg(0, t->img, x, y);
	else
		ft_put_pixtoimg(t->color_map[i * (COL_NB - 1) / t->max_iter],
						t->img, x, y);
}

void	ft_pix_rabbit(t_tool *t, int x, int y)
{
	t_point	z;
	t_point	c;
	t_point	tmp;
	int		i;

	z = ft_newpoint((double)x / ((double)W / (t->x2 - t->x1)) + t->x1,
					(double)y / ((double)H / (t->y2 - t->y1)) + t->y1);
	c = ft_newpoint(-0.12, 0.75);
	tmp = ft_newpoint(0, 0);
	i = 0;
	while (z.r * z.r + z.i * z.i < 2.015 && i < t->max_iter)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2.0 * tmp.r * tmp.i + c.i;
		i++;
	}
	if (i == t->max_iter)
		ft_put_pixtoimg(0, t->img, x, y);
	else
		ft_put_pixtoimg(t->color_map[i * (COL_NB - 1) / t->max_iter],
						t->img, x, y);
}

void	ft_put_fractal(t_tool *t)
{
	int		x;
	int		y;

	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			if (t->type_fract == 1)
				ft_pix_julia(t, x, y);
			else if (t->type_fract == 2)
				ft_pix_mandelbrot(t, x, y);
			else if (t->type_fract == 3)
				ft_pix_rabbit(t, x, y);
			y++;
		}
		x++;
	}
}
