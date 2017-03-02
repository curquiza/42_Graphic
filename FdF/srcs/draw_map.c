/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:07:55 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 17:32:01 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_allmap(t_img *img, t_point **map, int mode)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < map[i][0].linelen)
		{
			if (j != map[0][0].linelen - 1)
				ft_draw_line(img, map[i][j].pix, map[i][j + 1].pix, mode);
			else
				ft_draw_line(img, map[i][j].pix, NULL, mode);
			if (map[i + 1])
				ft_draw_line(img, map[i][j].pix, map[i + 1][j].pix, mode);
			j++;
		}
		i++;
	}
}
