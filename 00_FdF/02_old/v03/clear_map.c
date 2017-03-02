/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:28:04 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 17:33:02 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_1(t_img *img, t_pix *start, t_pix *end)
{
	t_pix	*move;
	t_pix	*inc;
	t_pix	*d;
	int		cumul;
	int		i;

	move = ft_new_pix(start->x, start->y, W);
	d = ft_new_pix(ft_abs(end->x - start->x), ft_abs(end->y - start->y), W);
	inc = ft_new_pix((end->x - start->x > 0) ? 1 : -1,
						(end->y - start->y > 0) ? 1 : -1, W);
	cumul = d->x / 2;
	i = 1;
	while (i <= d->x)
	{
		move->x = move->x + inc->x;
		cumul = cumul + d->y;
		if (cumul >= d->x)
		{
			cumul = cumul - d->x;
			move->y = move->y + inc->y;
		}
		ft_put_pixtoimg(0, img, move->x, move->y);
		i++;
	}
}

void	ft_clear_2(t_img *img, t_pix *start, t_pix *end)
{
	t_pix	*move;
	t_pix	*inc;
	t_pix	*d;
	int		cumul;
	int		i;

	move = ft_new_pix(start->x, start->y, W);
	d = ft_new_pix(ft_abs(end->x - start->x), ft_abs(end->y - start->y), W);
	inc = ft_new_pix((end->x - start->x > 0) ? 1 : -1,
						(end->y - start->y > 0) ? 1 : -1, W);
	cumul = d->y / 2;
	i = 1;
	while (i <= d->y)
	{
		move->y = move->y + inc->y;
		cumul = cumul + d->x;
		if (cumul >= d->y)
		{
			cumul = cumul - d->y;
			move->x = move->x + inc->x;
		}
		ft_put_pixtoimg(0, img, move->x, move->y);
		i++;
	}
}

void	ft_clear_line(t_img *img, t_pix *start, t_pix *end)
{
	int		dx;
	int		dy;

	if (!start && end)
		ft_put_pixtoimg(0, img, end->x, end->y);
	else if (start && !end)
		ft_put_pixtoimg(0, img, start->x, start->y);
	else if (start && end)
	{
		dx = ft_abs(end->x - start->x);
		dy = ft_abs(end->y - start->y);
		ft_put_pixtoimg(0, img, start->x, start->y);
		if (dx > dy)
			ft_clear_1(img, start, end);
		else
			ft_clear_2(img, start, end);
	}
}

void		ft_clear_allmap(t_img *img, t_point **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < map[i][0].linelen)
		{;
			if (j != map[0][0].linelen - 1)
				ft_clear_line(img, map[i][j].pix, map[i][j + 1].pix);
			else
				ft_clear_line(img, map[i][j].pix, NULL);
			if (map[i + 1])
				ft_clear_line(img, map[i][j].pix, map[i + 1][j].pix);
			j++;
		}
		i++;
	}
}
