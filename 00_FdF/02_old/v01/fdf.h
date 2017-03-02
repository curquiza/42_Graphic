#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"


# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF
# define W 0x00FFFFFF
# define TITLE "FdF"

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
#endif
