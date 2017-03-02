/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:18:57 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/02 11:12:04 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	return (value >= 0 ? value : -1 * value);
}

t_point	**ft_parsing(int ac, char **av)
{
	t_list		*lst_file;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fdf <filename>", 2);
		return (NULL);
	}
	if (!(lst_file = ft_readfile(av[1])))
	{
		ft_putendl_fd("No data found.", 2);
		return (NULL);
	}
	if (ft_check_length(lst_file) == -1)
	{
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
		return (NULL);
	}
	return (ft_create_map(lst_file));
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
