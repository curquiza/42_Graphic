/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:58:03 by curquiza          #+#    #+#             */
/*   Updated: 2017/02/24 20:16:36 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_readfile(char *source)
{
	int		fd;
	char	*line;
	int		ret;
	t_list	*file;

	line = NULL;
	file = NULL;
	ret = 0;
	if ((fd = open(source, O_RDONLY)) < 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putendl_fd(source, 2);
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_lstadd_back(&file, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (ret == -1)
		return (NULL);
	if (close(fd) < 0)
		return (NULL);
	return (file);
}

int		ft_count_pts(char *s)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (*s)
			cnt++;
		while (*s && *s != ' ' && *s != '\t')
			s++;
	}
	return (cnt);
}

int		ft_check_length(t_list *lst_file)
{
	int		len;

	len = ft_count_pts(lst_file->content);
	while (lst_file)
	{
		if (len != ft_count_pts(lst_file->content))
			return (-1);
		lst_file = lst_file->next;
	}
	return (0);
}
