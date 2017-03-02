/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:20:22 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/02 11:19:09 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_pgmenv *recup, int w, int h)
{
	int		i;
	int		j;

	ft_clear_allmap(recup->img, recup->map);
	i = 0;
	while (recup->map[i])
	{
		j = 0;
		while (j < recup->map[0][0].linelen)
		{
			recup->map[i][j].pix->x += w;
			recup->map[i][j].pix->y += h;
			j++;
		}
		i++;
	}
	if (recup->img->col == 1)
		ft_draw_allmap(recup->img, recup->map, 1);
	else
		ft_draw_allmap(recup->img, recup->map, 0);
	mlx_put_image_to_window(recup->env->mlx, recup->env->win,
							recup->img->image, 19, 19);
}

void	ft_show_colors(t_pgmenv *recup)
{
	if (recup->img->col)
		recup->img->col = 0;
	else
		recup->img->col = 1;
	ft_draw_allmap(recup->img, recup->map, recup->img->col);
	mlx_put_image_to_window(recup->env->mlx, recup->env->win,
							recup->img->image, 19, 19);
}

int		ft_fct_pgmenv(int keycode, t_pgmenv *recup)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123 && recup)
		ft_move(recup, -10, 0);
	else if (keycode == 124 && recup)
		ft_move(recup, 10, 0);
	else if (keycode == 125 && recup)
		ft_move(recup, 0, 10);
	else if (keycode == 126 && recup)
		ft_move(recup, 0, -10);
	else if (keycode == 8 && recup)
		ft_show_colors(recup);
	return (0);
}
