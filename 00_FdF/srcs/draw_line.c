/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:22:41 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 17:18:16 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_colortopix(int rslt, int mode, t_pix *start, t_pix *end)
{
	if (rslt == 1 && mode == 1)
		return (start->col);
	if (rslt == 0 && mode == 1)
		return (end->col);
	return (W);
}

void	ft_write_1(t_img *img, t_pix *start, t_pix *end, int mode)
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
		ft_put_pixtoimg(ft_colortopix(i <= d->x / 2 ? 1 : 0, mode, start, end),
						img, move->x, move->y);
		i++;
	}
}

void	ft_write_2(t_img *img, t_pix *start, t_pix *end, int mode)
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
		ft_put_pixtoimg(ft_colortopix(i <= d->y / 2 ? 1 : 0, mode, start, end),
						img, move->x, move->y);
		i++;
	}
}

void	ft_draw_line(t_img *img, t_pix *start, t_pix *end, int mode)
{
	int		dx;
	int		dy;

	if (!start && end)
		ft_put_pixtoimg(mode == 1 ? end->col : W, img, end->x, end->y);
	else if (start && !end)
		ft_put_pixtoimg(mode == 1 ? start->col : W, img, start->x, start->y);
	else if (start && end)
	{
		dx = ft_abs(end->x - start->x);
		dy = ft_abs(end->y - start->y);
		ft_put_pixtoimg(mode == 1 ? start->col : W, img, start->x, start->y);
		if (dx > dy)
			ft_write_1(img, start, end, mode);
		else
			ft_write_2(img, start, end, mode);
	}
}
