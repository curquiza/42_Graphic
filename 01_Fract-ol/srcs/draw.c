/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:50:16 by curquiza          #+#    #+#             */
/*   Updated: 2017/08/23 18:52:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixtoimg(int col, t_img *img, int x, int y)
{
	int		pos;

	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	pos = y * img->sizeline + x * img->bpp / 8;
	if (pos < H * img->sizeline)
	{
		img->data[pos] = col & 0x000000FF;
		img->data[pos + 1] = col >> 8 & 0x000000FF;
		img->data[pos + 2] = col >> 16 & 0x000000FF;
		img->data[pos + 3] = col >> 24 & 0x000000FF;
	}
}

int		ft_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
