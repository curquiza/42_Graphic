#include "fdf.h"

int		my_key_func(int keycode, void *param)
{
	(void)param;
	printf("keycode = %d\n", keycode);
	return (0);
}

int		ft_escape(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

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
			ft_putnbr(map[i][j].alti);
			if (map[i][j].color != 0x00FFFFFF)
			{
				ft_putchar(',');
				ft_putnbr(map[i][j].color);
			}
			ft_putstr("\t");
			j++;
		}
		ft_putendl("");
		i++;	
	}
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
			ft_putstr("\t");
			j++;
		}
		ft_putendl("");
		i++;	
	}
}

int		main(int ac, char **av)
{
	t_param	*param;
	t_env	*env;
	t_img	*img;
	t_point	**map;

//	env = NULL;
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
		ft_draw_allmap(img, map);
		mlx_put_image_to_window(env->mlx, env->win, img->image, 19, 19);
	}
	//ft_draw_line(R, img, ft_new_pix(0, 0), ft_new_pix(0, 99));
	//ft_draw_line(R, img, ft_new_pix(0, 0), ft_new_pix(99, 0));
	//ft_draw_line(R, img, ft_new_pix(0, 99), ft_new_pix(99, 99));
	//ft_draw_line(R, img, ft_new_pix(99, 0), ft_new_pix(99, 99));
	/*ft_draw_line(W, img, ft_new_pix(150, 15), ft_new_pix(15, 30));
	ft_draw_line(W, img, ft_new_pix(10, 10), NULL);
	ft_draw_line(W, img, NULL, ft_new_pix(50, 50));
	ft_draw_line(W, img, NULL, NULL);*/

	mlx_key_hook(env->win, ft_escape, 0);
	mlx_loop(env->mlx);
	return (0);
}
