/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:10:47 by curquiza          #+#    #+#             */
/*   Updated: 2017/02/27 11:02:21 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**ft_parsing(int ac, char **av)
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
