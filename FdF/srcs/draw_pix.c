/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:09:56 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 16:12:23 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
