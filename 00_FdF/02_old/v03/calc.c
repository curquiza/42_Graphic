/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:08:44 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 19:06:59 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_calc_size_imgandwin(t_point **map, t_param *param)
{
	int		i;
	int		j;
	int		max_x;
	int		max_y;

	max_x = 0;
	max_y = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < map[0][0].linelen)
		{
			if (max_x < map[i][j].pix->x)
				max_x = map[i][j].pix->x;
			if (max_y < map[i][j].pix->y)
				max_y = map[i][j].pix->y;
			j++;
		}
		i++;
	}
	param->img_h = (max_y > WINMAX_Y) ? WINMAX_Y : max_y + 1;
	param->img_w = (max_x > WINMAX_X) ? WINMAX_X : max_x + 1;
	param->win_h = param->img_h + 40;
	param->win_w = param->img_w + 40;
}

void		ft_calc_basiccoord(t_point **map, t_param *param)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (map[i])
		i++;
	x = 0;
	y = (i - 1) * param->unit;
	i--;
	while (i >= 0)
	{
		j = -1;
		while (++j < map[0][0].linelen)
		{
			map[i][j].pix->x = x;
			map[i][j].pix->y = y;
			map[i][j].y_init = y;
			x = x + param->unit;
		}
		y = y - param->unit;
		x = map[i][0].pix->x + param->unit;
		i--;
	}
}

void		ft_calc_withalti(t_point **map, t_param *param)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < map[0][0].linelen)
		{
			if (map[i][j].alti)
				map[i][j].pix->y = map[i][j].y_init
								+ (-1) * map[i][j].alti * param->coef_alti;
			j++;
		}
		i++;
	}
}

void		ft_adjust_coord(t_point **map)
{
	int		i;
	int		j;
	int		move;

	move = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < map[0][0].linelen)
		{
			if (map[i][j].pix->y < 0 && move < ft_abs(map[i][j].pix->y))
				move = ft_abs(map[i][j].pix->y);
		}
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < map[0][0].linelen)
		{
			map[i][j].pix->y = map[i][j].pix->y + move;
			map[i][j].y_init = map[i][j].pix->y;
		}
	}
}

void		ft_calc_all(t_point **map, t_param *param)
{
	ft_calc_basiccoord(map, param);
	ft_calc_withalti(map, param);
	ft_adjust_coord(map);
	ft_calc_size_imgandwin(map, param);
}
