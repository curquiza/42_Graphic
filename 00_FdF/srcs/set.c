/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:04:34 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 18:55:25 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param		*ft_set_param(t_point **map)
{
	t_param	*param;
	int		i;

	i = 0;
	while (map[i])
		i++;
	if (!(param = (t_param *)malloc(sizeof(*param))))
		return (NULL);
	if (map[0][0].linelen > LIM_3_4 || i > LIM_3_4)
		param->unit = UNIT4;
	else if (map[0][0].linelen > LIM_2_3 || i > LIM_2_3)
		param->unit = UNIT3;
	else if (map[0][0].linelen > LIM_1_2 || i > LIM_1_2)
		param->unit = UNIT2;
	else
		param->unit = UNIT1;
	param->coef_alti = COEF_ALTI;
	param->win_h = 0;
	param->win_w = 0;
	param->img_h = 0;
	param->img_w = 0;
	return (param);
}

t_env		*ft_set_env(int win_x, int win_y)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(*env))))
		return (NULL);
	if (!(env->mlx = mlx_init()))
	{
		ft_putendl_fd("Init error", 2);
		exit(1);
	}
	if (!(env->win = mlx_new_window(env->mlx, win_x, win_y, TITLE)))
	{
		ft_putendl_fd("Window error", 2);
		exit(1);
	}
	return (env);
}

t_img		*ft_seteandget_img(t_env *env, int imgsize_x, int imgsize_y)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		return (NULL);
	if (!(img->image = mlx_new_image(env->mlx, imgsize_x, imgsize_y)))
		exit(1);
	img->size_x = imgsize_x;
	img->size_y = imgsize_y;
	img->bpp = 32;
	img->endian = 1;
	img->sizeline = 4 * imgsize_y;
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->sizeline,
			&img->endian);
	img->col = 0;
	return (img);
}

t_pix		*ft_new_pix(int x, int y, int col)
{
	t_pix	*pix;

	if (!(pix = (t_pix *)malloc(sizeof(*pix))))
		return (NULL);
	pix->x = x;
	pix->y = y;
	pix->col = col;
	return (pix);
}

t_pgmenv	*ft_set_pgmenv(t_point **map, t_param *param, t_img *img,
							t_env *env)
{
	t_pgmenv	*rslt;

	if (img == NULL || param == NULL)
		return (NULL);
	if (!(rslt = (t_pgmenv *)malloc(sizeof(*rslt))))
		return (NULL);
	rslt->map = map;
	rslt->param = param;
	rslt->img = img;
	rslt->env = env;
	return (rslt);
}
