#include "fdf.h"
#include <stdio.h>

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

void	ft_draw1(t_env env)
{
	int		col;
	int		x;
	int		y;

	x = 0;
	y = 50;
	col = 0;
	while (y < 800)
	{
		x = 50;
		//col = 0;
		while (x < 800)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, 0x0000FF);
		//	mlx_pixel_put(env.mlx, env.win, x, y, col);
			//if (col >= 0xFFFFFF || col < 0)
			//	col = 0;
			//if (col >= 0x00FF00)
			//	col = col + 0x050000;
			//else if (col >= 0x0000FF)
			//	col = col + 0x000500;
			//else
			//	col = col + 0x000005;
			//if (y == 50)
			//	printf("%#x ", col);
			col++;
			x++;
		}
		y++;
	}
	//printf("int de col = %#x\n", mlx_get_color_value(env.mlx, 0x0000100));
}

int		main(void)
{
	t_env	env;
	void	*image;
	char	*data;
//	int		*data;
	int		bits_per_pixel;
	int		endian;
	int		size_line;

	if (!(env.mlx = mlx_init()))
		exit(1);
	if (!(env.win = mlx_new_window(env.mlx, 1000, 1000, "FdF")))
		exit(1);
	//ft_draw1(env);
	mlx_key_hook(env.win, ft_escape, 0);

	if (!(image = mlx_new_image(env.mlx, 10, 10)))
		exit(1);
	bits_per_pixel = 4;
	endian = 1;
	size_line = 100;
	data = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
//	*data = 0x00FFFFFF;
//	data = data + 12;
//	*data = 0x00FFFFFF;
	data[0] = 0x00;
	data[1] = 0x00;
	data[2] = 0xFF;
	data[3] = 0x00;
	mlx_put_image_to_window(env.mlx, env.win, image, 900, 900);
	

	mlx_loop(env.mlx);
	return (0);
}
