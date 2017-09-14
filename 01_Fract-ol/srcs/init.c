/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:47:56 by curquiza          #+#    #+#             */
/*   Updated: 2017/08/23 18:53:27 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_newpoint(double r, double i)
{
	t_point	pt;

	pt.r = r;
	pt.i = i;
	return (pt);
}

t_img	*ft_set_img(t_tool *t)
{
	t_img	*img;

	img = ft_memalloc(sizeof(*img));
	if (!(img->image = mlx_new_image(t->mlx, W, H)))
		exit(1);
	img->bpp = 32;
	img->endian = 1;
	img->sizeline = 4 * W;
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->sizeline,
									&img->endian);
	return (img);
}

void	ft_init_fract(t_tool *t)
{
	if (t->type_fract == 1)
	{
		t->x1 = -1.5;
		t->x2 = 1.5;
		t->y1 = -1;
		t->y2 = 1;
		t->move_julia = 1;
	}
	else if (t->type_fract == 2)
	{
		t->x1 = -2.1;
		t->x2 = 0.6;
		t->y1 = -1.2;
		t->y2 = 1.2;
		t->move_mandel = 0;
	}
	else
	{
		t->x1 = -2;
		t->x2 = 2;
		t->y1 = -2;
		t->y2 = 2;
	}
	t->mouse_x = 0;
	t->mouse_y = 0;
}

void	ft_init_color_map(t_tool *t)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = PALETTE_SIZE - 1;
	while (i < PALETTE_SIZE)
	{
		t->color_map[i] = ft_rgb(i, 0, i);
		t->color_map[i + PALETTE_SIZE] = ft_rgb(tmp - i, 0, tmp);
		t->color_map[i + PALETTE_SIZE * 2] = ft_rgb(0, i, tmp);
		t->color_map[i + PALETTE_SIZE * 3] = ft_rgb(0, tmp, tmp - i);
		t->color_map[i + PALETTE_SIZE * 4] = ft_rgb(i, tmp, 0);
		t->color_map[i + PALETTE_SIZE * 5] = ft_rgb(tmp, tmp - i, 0);
		t->color_map[i + PALETTE_SIZE * 6] = ft_rgb(tmp - i, 0, 0);
		i++;
	}
}

t_tool	*ft_set_tool(int type_fract)
{
	t_tool		*t;

	t = ft_memalloc(sizeof(*t));
	if (!(t->mlx = mlx_init()))
	{
		ft_putendl_fd("Init error", 2);
		exit(1);
	}
	if (!(t->win = mlx_new_window(t->mlx, W, H, TITLE)))
	{
		ft_putendl_fd("Window error", 2);
		exit(1);
	}
	t->type_fract = type_fract;
	t->img = ft_set_img(t);
	if (type_fract == 1)
		t->max_iter = MAX_ITER_JULIA;
	else if (type_fract == 2)
		t->max_iter = MAX_ITER_MANDEL;
	else
		t->max_iter = MAX_ITER_RABBIT;
	ft_init_fract(t);
	t->move_julia = (t->type_fract == 1) ? 1 : 0;
	ft_init_color_map(t);
	return (t);
}
