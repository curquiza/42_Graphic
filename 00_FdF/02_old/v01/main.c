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

void	ft_put_pixtoimg(int col, t_img *img, int x, int y)
{
	//printf("put_pixtoimg = %d\n", y * img->sizeline + x * img->bpp / 8);
	img->data[y * img->sizeline + x * img->bpp / 8] = col & 0x000000FF;
	img->data[y * img->sizeline + x * img->bpp / 8 + 1] = col >> 8 & 0x000000FF;
	img->data[y * img->sizeline + x * img->bpp / 8 + 2] = col >> 16 & 0x000000FF;
	img->data[y * img->sizeline + x * img->bpp / 8 + 3] = col >> 24 & 0x000000FF;
}

t_env	ft_set_env(int win_x, int win_y)
{
	t_env	env;

	if (!(env.mlx = mlx_init()))
	{
		ft_putendl_fd("Init error", 2);
		exit(1);
	}
	if (!(env.win = mlx_new_window(env.mlx, win_x, win_y, TITLE)))
	{
		ft_putendl_fd("Window error", 2);
		exit(1);
	}
	return (env);
}

t_img	*ft_seteandget_img(t_env env, int imgsize_x, int imgsize_y)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		return (NULL);
	if (!(img->image = mlx_new_image(env.mlx, imgsize_x, imgsize_y)))
		exit(1);
	img->size_x = imgsize_x;
	img->size_y = imgsize_y;
	img->bpp = 32;
	img->endian = 1;
	img->sizeline = 4 * imgsize_y;
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->sizeline,
									&img->endian);
	return (img);
}

void	ft_draw_line(int col, t_img *img, t_pix *start, t_pix *end)
{
	int		dx;
	int		dy;
	int		x;
	int		y;

	if (start == NULL)
		ft_put_pixtoimg(col, img, end->x, end->y);
	else if (end == NULL)
		ft_put_pixtoimg(col, img, start->x, start->y);
	else
	{
		dy = end->y - start->y;
		dx = end->x - start->x;
		x = start->x;
		y = start->y;
		while (x <= end->x && y <= end->y && x < img->size_x && y < img->size_y)
		{
			ft_put_pixtoimg(col, img, x, y);
			if (dx)
			{
				x++;
				y = (dy / dx) * (x - start->x) + start->y;
			}
			else
				y++;
			//printf("x = %d ; y = %d\n", x, y);
		}
	}
}

/*void	ft_draw_line(int col, t_img *img, t_pix *start, t_pix *end)
{
	int		coef;
	int		move;
	int		new_point;

	if (start == NULL)
		ft_put_pixtoimg(col, img, end->x, end->y);
	else if (end == NULL)
		ft_put_pixtoimg(col, img, start->x, start->y);

	if (end->x - start->x == 0)
	{
		move = start->y;
		while (move != end->y)
		{
			ft_put_pixtoimg(col, img, start->x, move);
			move < end->y ? move++: move--;
		}
	}
	else
	{
		move = start->x;
		coef = (end->y - start->y) / (end->x - start->x);
		while (move != end->x)
		{
			//new_point = start->y - coef * (start->x - move);
			new_point = move * coef;
			ft_put_pixtoimg(col, img, move, new_point);
			printf("x = %d ; y = %d\n", move, new_point);
			move < end->x ? move++: move--;
		}
		ft_put_pixtoimg(col, img, end->x, end->y);
		//printf("x = %d ; y = %d\n", end->x, end->y);
	}
}*/

t_pix	*ft_new_point(int x, int y)
{
	t_pix	*point;

	if (!(point = (t_pix *)malloc(sizeof(*point))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

int		main(void)
{
	t_env	env;
	t_img	*img;

	env = ft_set_env(500, 500);
	mlx_key_hook(env.win, ft_escape, 0);
	img = ft_seteandget_img(env, 100, 100);
	ft_put_pixtoimg(R, img, 0, 0);
	ft_put_pixtoimg(R, img, 99, 0);
	ft_put_pixtoimg(R, img, 0, 99);
	ft_put_pixtoimg(R, img, 99, 99);
	ft_draw_line(W, img, ft_new_point(10, 10), ft_new_point(20, 10));
	//ft_draw_line(W, img, ft_new_point(10, 10), NULL);
	//ft_draw_line(W, img, NULL, ft_new_point(50, 50));
	mlx_put_image_to_window(env.mlx, env.win, img->image, 100, 100);
	mlx_loop(env.mlx);
	return (0);
}
