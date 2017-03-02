/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:20:22 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 19:06:29 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void		ft_calc_newalti(t_point **map, t_param *param)
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
}*/

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
	/*else if (keycode == 69 && recup)
	{
		ft_clear_allmap(recup->img, recup->map);
		(recup->param->coef_alti)++;
		ft_calc_newalti(recup->map, recup->param);
		if (recup->img->col == 1)
			ft_draw_allmap(recup->img, recup->map, 1);
		else
			ft_draw_allmap(recup->img, recup->map, 0);
		mlx_put_image_to_window(recup->env->mlx, recup->env->win,
								recup->img->image, 19, 19);
	}
	else if (keycode == 78 && recup)
	{
		ft_clear_allmap(recup->img, recup->map);
		printf("alti avant : %d\n", recup->param->coef_alti);
		(recup->param->coef_alti)--;
		printf("alti apres : %d\n", recup->param->coef_alti);
		ft_putmap_coord(recup->map);
		ft_calc_newalti(recup->map, recup->param);
		ft_putmap_coord(recup->map);
		if (recup->img->col == 1)
			ft_draw_allmap(recup->img, recup->map, 1);
		else
			ft_draw_allmap(recup->img, recup->map, 0);
		mlx_put_image_to_window(recup->env->mlx,
								recup->env->win, recup->img->image, 19, 19);
	}*/
	else if (keycode == 123)
		ft_move(recup, -10, 0);
	else if (keycode == 124)
		ft_move(recup, 10, 0);
	else if (keycode == 125)
		ft_move(recup, 0, 10);
	else if (keycode == 126)
		ft_move(recup, 0, -10);
	else if (keycode == 8 && recup)
		ft_show_colors(recup);
	return (0);
}
