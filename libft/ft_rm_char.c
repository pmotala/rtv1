/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <pmotala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:42:40 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 09:54:07 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rm_char(char *dest, char c)
{
	int		removed;
	char	*tmp;
	size_t	len;

	removed = 0;
	while (*dest)
	{
		tmp = ft_strchr(dest, c);
		if (tmp == NULL)
			break ;
		len = ft_strlen(tmp + 1);
		ft_memmove(tmp, tmp + 1, len);
		tmp[len] = 0;
		++removed;
		dest = tmp;
	}
	return (removed);
}
