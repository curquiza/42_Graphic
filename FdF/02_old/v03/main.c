/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:18:57 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 18:37:27 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	return (value >= 0 ? value : -1 * value);
}

/*int		my_key_func(int keycode, void *param)
{
	(void)param;
	printf("keycode = %d\n", keycode);
	return (0);
}*/

void	ft_puttlist(t_list *list)
{
	while (list)
	{
		ft_putendl(list->content);
		list = list->next;
	}
}

void	ft_putmap(t_point **map)
{
	int		i;
	int		j;

	ft_putstr("linelen = ");
	ft_putnbr_endl(map[0][0].linelen);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (j < map[i][0].linelen)
		{
			/*ft_putnbr(map[i][j].alti);
			if (map[i][j].color != 0x00FFFFFF)
			{
				ft_putchar(',');
				ft_putnbr(map[i][j].color);
			}
			ft_putstr("\t");*/
			j++;
		}
		//ft_putendl("");
		i++;	
	}
	printf("h = %d\n", i);
}

void	ft_putmap_coord(t_point **map)
{
	int		i;
	int		j;

	ft_putstr("linelen = ");
	ft_putnbr_endl(map[0][0].linelen);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (j < map[i][0].linelen)
		{
			ft_putnbr(map[i][j].pix->x);
			ft_putchar(',');
			ft_putnbr(map[i][j].pix->y);
			ft_putchar(',');
			ft_putnbr(map[i][j].y_init);
			ft_putstr("\t");
			j++;
		}
		ft_putendl("");
		i++;	
	}
}

int		main(int ac, char **av)
{
	t_param		*param;
	t_env		*env;
	t_img		*img;
	t_point		**map;

	param = NULL;
	img = NULL;
	if ((map = ft_parsing(ac, av)) == NULL)
		return (1);
	ft_putmap(map);
	if (map[0] == NULL || map[0][0].linelen == 0)
		env = ft_set_env(50, 50);
	else
	{
		param = ft_set_param(map);
		ft_calc_all(map, param);	
		env = ft_set_env(param->win_w, param->win_h);
		img = ft_seteandget_img(env, param->img_w, param->img_h);
		ft_draw_allmap(img, map, 0);
		mlx_put_image_to_window(env->mlx, env->win, img->image, 19, 19);
	}
	mlx_key_hook(env->win, ft_fct_pgmenv, ft_set_pgmenv(map, param, img, env));
	mlx_loop(env->mlx);
	return (0);
}
