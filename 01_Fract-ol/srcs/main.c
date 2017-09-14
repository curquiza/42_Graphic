/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:48:59 by curquiza          #+#    #+#             */
/*   Updated: 2017/08/23 18:49:00 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_get_argument(int ac, char **av)
{
	char	*arg;
	int		ret;

	ret = -1;
	if (ac <= 1)
		ft_putendl_fd("One argument needed\n-------", 2);
	else if (ac > 2)
		ft_putendl_fd("Only one argument needed\n-------", 2);
	else
	{
		arg = ft_strdup(av[1]);
		ft_strlower(arg);
		if (ft_strcmp(arg, "julia") == 0)
			ret = 1;
		else if (ft_strcmp(arg, "mandelbrot") == 0)
			ret = 2;
		else if (ft_strcmp(arg, "rabbit") == 0)
			ret = 3;
		else
			ft_putendl_fd("Not a valid argument\n-------", 2);
		ft_strdel(&arg);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	t_tool	*t;
	int		type_fract;

	if ((type_fract = ft_get_argument(ac, av)) == -1)
	{
		ft_putendl_fd("Give as argument :", 2);
		ft_putendl_fd("\"julia\" to display the julia's fractal", 2);
		ft_putendl_fd("\"mandelbrot\" to display the mandelbrot's fractal", 2);
		ft_putendl_fd("\"rabbit\" to display the rabbit's fractal", 2);
		return (1);
	}
	t = ft_set_tool(type_fract);
	ft_put_fractal(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img->image, 0, 0);
	mlx_key_hook(t->win, &ft_event_key, t);
	mlx_mouse_hook(t->win, &ft_event_mouse, t);
	if (type_fract == 1 || type_fract == 2)
		mlx_hook(t->win, 6, 0, ft_mouse_pos, t);
	mlx_loop(t->mlx);
	return (0);
}
