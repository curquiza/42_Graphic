/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:27:32 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/12 17:46:21 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Faire un strnew et pas un simple malloc car si la longueur de s est plus
** petite que len, alors la fin de tmp sera remplie par des char inconnus.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	return (tmp);
}
