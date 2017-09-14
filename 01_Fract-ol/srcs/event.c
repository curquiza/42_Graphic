/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:54:57 by curquiza          #+#    #+#             */
/*   Updated: 2017/08/23 17:27:38 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_fract(t_tool *t, int keycode)
{
	mlx_clear_window(t->mlx, t->win);
	t->img = ft_set_img(t);
	if (keycode == 123)
	{
		t->x1 = t->x1 + 0.01;
		t->x2 = t->x2 + 0.01;
	}
	else if (keycode == 124)
	{
		t->x1 = t->x1 - 0.01;
		t->x2 = t->x2 - 0.01;
	}
	else if (keycode == 126)
	{
		t->y1 = t->y1 + 0.01;
		t->y2 = t->y2 + 0.01;
	}
	else if (keycode == 125)
	{
		t->y1 = t->y1 - 0.01;
		t->y2 = t->y2 - 0.01;
	}
	ft_put_fractal(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img->image, 0, 0);
}

int		ft_event_key(int keycode, t_tool *t)
{
	if (keycode == 82)
	{
		mlx_clear_window(t->mlx, t->win);
		t->img = ft_set_img(t);
		ft_init_fract(t);
		ft_put_fractal(t);
		mlx_put_image_to_window(t->mlx, t->win, t->img->image, 0, 0);
	}
	else if (keycode == 49)
	{
		if (t->type_fract == 1 && t->move_julia == 1)
			t->move_julia = 0;
		else if (t->type_fract == 1 && t->move_julia == 0)
			t->move_julia = 1;
		else if (t->type_fract == 2 && t->move_mandel == 1)
			t->move_mandel = 0;
		else if (t->type_fract == 2 && t->move_mandel == 0)
			t->move_mandel = 1;
	}
	else if (keycode == 126 || keycode == 123 || keycode == 125
			|| keycode == 124)
		ft_move_fract(t, keycode);
	else if (keycode == 53)
		exit(1);
	return (0);
}

void	ft_zoom(double x, double y, t_tool *t, double coef)
{
	double	d_x;
	double	d_y;
	double	x_tmp;
	double	y_tmp;
	double	tmp;

	x_tmp = (x * (t->x2 - t->x1) / W) + t->x1;
	y_tmp = (y * (t->y2 - t->y1) / H) + t->y1;
	mlx_clear_window(t->mlx, t->win);
	t->img = ft_set_img(t);
	d_x = t->x2 - t->x1;
	d_y = t->y2 - t->y1;
	tmp = t->x1;
	t->x1 = (x_tmp + (t->x2 + t->x1) / 2) / 2 - d_x * coef;
	t->x2 = (x_tmp + (t->x2 + tmp) / 2) / 2 + d_x * coef;
	tmp = t->y1;
	t->y1 = (y_tmp + (t->y2 + t->y1) / 2) / 2 - d_y * coef;
	t->y2 = (y_tmp + (t->y2 + tmp) / 2) / 2 + d_y * coef;
	ft_put_fractal(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img->image, 0, 0);
}

int		ft_event_mouse(int button, int x, int y, t_tool *t)
{
	if (button == 4)
		ft_zoom(x, y, t, 0.6);
	else if (button == 5)
		ft_zoom(x, y, t, 0.4);
	return (0);
}

int		ft_mouse_pos(int x, int y, t_tool *t)
{
	if (t->move_julia == 1 || t->move_mandel == 1)
	{
		t->mouse_x = x / (W / (t->x2 - t->x1)) + t->x1;
		t->mouse_y = y / (H / (t->y2 - t->y1)) + t->y1;
		mlx_clear_window(t->mlx, t->win);
		t->img = ft_set_img(t);
		ft_put_fractal(t);
		mlx_put_image_to_window(t->mlx, t->win, t->img->image, 0, 0);
	}
	return (0);
}
