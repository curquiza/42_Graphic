/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:22:41 by curquiza          #+#    #+#             */
/*   Updated: 2017/02/27 19:11:49 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	return (value >= 0 ? value : -1 * value);
}

void	ft_put_pixtoimg(int col, t_img *img, int x, int y)
{
	int		pos;

	if (x < 0 || y < 0 || x >= img->size_x || y >= img->size_y)
		return ;
	pos = y * img->sizeline + x * img->bpp / 8;
	if (pos < img->size_y * img->sizeline)
	{
		img->data[pos] = col & 0x000000FF;
		img->data[pos + 1] = col >> 8 & 0x000000FF;
		img->data[pos + 2] = col >> 16 & 0x000000FF;
		img->data[pos + 3] = col >> 24 & 0x000000FF;
	}
}

void	ft_write_1(int col, t_img *img, t_pix *start, t_pix *end)
{
	t_pix	*move;
	t_pix	*inc;
	t_pix	*d;
	int		cumul;
	int		i;

	move = ft_new_pix(start->x, start->y);
	d = ft_new_pix(ft_abs(end->x - start->x), ft_abs(end->y - start->y));
	inc = ft_new_pix((end->x - start->x > 0) ? 1 : -1,
						(end->y - start->y > 0) ? 1 : -1);
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
		ft_put_pixtoimg(col, img, move->x, move->y);
		i++;
	}
}

void	ft_write_2(int col, t_img *img, t_pix *start, t_pix *end)
{
	t_pix	*move;
	t_pix	*inc;
	t_pix	*d;
	int		cumul;
	int		i;

	move = ft_new_pix(start->x, start->y);
	d = ft_new_pix(ft_abs(end->x - start->x), ft_abs(end->y - start->y));
	inc = ft_new_pix((end->x - start->x > 0) ? 1 : -1,
						(end->y - start->y > 0) ? 1 : -1);
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
		ft_put_pixtoimg(col, img, move->x, move->y);
		i++;
	}
}

void	ft_draw_line(int col, t_img *img, t_pix *start, t_pix *end)
{
	int		dx;
	int		dy;

	if (!start && end)
		ft_put_pixtoimg(col, img, end->x, end->y);
	else if (start && !end)
		ft_put_pixtoimg(col, img, start->x, start->y);
	else if (start && end)
	{
		dx = ft_abs(end->x - start->x);
		dy = ft_abs(end->y - start->y);
		ft_put_pixtoimg(col, img, start->x, start->y);
		if (dx > dy)
			ft_write_1(col, img, start, end);
		else
			ft_write_2(col, img, start, end);
	}
}
