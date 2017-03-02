/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:10:12 by curquiza          #+#    #+#             */
/*   Updated: 2017/03/01 17:07:04 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_alti(char *s)
{
	int		i;
	char	*alti;
	int		alti_nbr;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != ',')
		i++;
	alti = ft_strsub(s, 0, i);
	if (alti == NULL)
		return (0);
	alti_nbr = ft_atoi(alti);
	ft_strdel(&alti);
	return (alti_nbr);
}

void		ft_conv_color(char **s)
{
	char	*tmp;
	char	*conv_col;
	int		i;

	i = 2;
	while ((*s)[i])
	{
		if (ft_isalnum((*s)[i]) == 0)
			return ;
		if ((*s)[i] >= 'a' && (*s)[i] <= 'f')
			(*s)[i] = (*s)[i] - 32;
		if (ft_isalpha((*s)[i]) && (*s)[i] > 'F')
			return ;
		i++;
	}
	tmp = *s;
	i = 2;
	while ((*s)[i] && (*s)[i] == '0')
		i++;
	*s = ft_strdup(tmp + i);
	ft_strdel(&tmp);
	conv_col = ft_convbase(*s, 16, 10);
	ft_strdeldup(s, conv_col);
	ft_strdel(&conv_col);
}

int			ft_get_color(char *s)
{
	int		end;
	char	*color;
	int		color_nbr;

	while (*s && *s != ' ' && *s != '\t' && *s != ',')
		s++;
	if (*s != ',')
		return (0x00FFFFFF);
	if (*s == ',' && (!(*(s + 1)) || *(s + 1) == ' ' || *(s + 1) == '\t'))
		return (0);
	s++;
	end = 0;
	while (s[end] && s[end] != ' ' && s[end] != '\t')
		end++;
	color = ft_strsub(s, 0, end);
	if (color == NULL)
		return (0);
	if (ft_strncmp(color, "0x", 2) == 0)
		ft_conv_color(&color);
	color_nbr = ft_atoi(color);
	ft_strdel(&color);
	if (color_nbr < 0)
		return (0x00FFFFFF);
	return (color_nbr);
}

void		ft_fill_mapline(char *s, t_point *map, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		map[i].alti = ft_get_alti(s);
		map[i].color = ft_get_color(s);
		map[i].linelen = len;
		map[i].pix = ft_new_pix(0, 0, map[i].color);
		map[i].y_init = 0;
		while (*s && *s != ' ' && *s != '\t')
			s++;
		i++;
	}
}

t_point		**ft_create_map(t_list *lst_file)
{
	int			len;
	int			i;
	t_point		**map;

	len = ft_lstlen(lst_file);
	map = (t_point **)malloc(sizeof(*map) * (len + 1));
	map[len] = NULL;
	i = 0;
	while (lst_file)
	{
		len = ft_count_pts(lst_file->content);
		map[i] = (t_point *)malloc(sizeof(**map) * (len + 1));
		ft_fill_mapline(lst_file->content, map[i], len);
		lst_file = lst_file->next;
		i++;
	}
	return (map);
}
