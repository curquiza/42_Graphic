#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

/*
** Defines
*/

# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF
# define W 0x00FFFFFF
# define TITLE "FdF"
# define WINMAX_X 2300
# define WINMAX_Y 1300
# define COEF_ALTI 5
# define LIM_1_2 20
# define LIM_2_3 50
# define UNIT1 20
# define UNIT2 10
# define UNIT3 5

/*
** Structures
*/

typedef struct	s_param
{
	int		unit;
	int		win_h;
	int		win_w;
	int		img_h;
	int		img_w;
}				t_param;

typedef struct	s_env
{
	void	*mlx;
	void	*win;	
}				t_env;

typedef struct	s_img
{
	void	*image;
	int		size_x;
	int		size_y;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef struct	s_pix
{
	int		x;
	int		y;
}				t_pix;

typedef struct	s_point
{
	int		alti;
	int		color;
	int		linelen;
	t_pix	*pix;
}				t_point;

/*
** set.c
*/

t_param			*ft_set_param(t_point **map);
t_env			*ft_set_env(int win_x, int win_y);
t_img			*ft_seteandget_img(t_env *env, int imgsize_x, int imgsize_y);
t_pix			*ft_new_pix(int x, int y);

/*
** get_file.c
*/

t_list			*ft_readfile(char *source);
int				ft_count_pts(char *s);
int				ft_check_length(t_list *lst_file);

/*
** map_parsing.c
*/

int				ft_get_alti(char *s);
void			ft_conv_color(char **s);
int				ft_get_color(char *s);
void			ft_fill_mapline(char *s, t_point *map, int len);
t_point			**ft_create_map(t_list *lst_file);

/*
** parsing.c
*/

t_point			**ft_parsing(int ac, char **av);

/*
** draw.c
*/

int				ft_abs(int value);
void			ft_write_1(int col, t_img *img, t_pix *start, t_pix *end);
void			ft_write_2(int col, t_img *img, t_pix *start, t_pix *end);
void			ft_put_pixtoimg(int col, t_img *img, int x, int y);
void			ft_draw_line(int col, t_img *img, t_pix *start, t_pix *end);

/*
** calc.c
*/

void			ft_calc_all(t_point **map, t_param *param);

/*
** draw_map.c
*/

void			ft_draw_allmap(t_img *img, t_point **map);

/*
** main.c
*/

void			ft_puttlist(t_list *list);
void			ft_putmap_coord(t_point **map);

#endif
