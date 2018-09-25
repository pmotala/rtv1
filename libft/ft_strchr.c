/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:51:06 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/01 10:37:10 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		pos;
	int		j;

	i = 0;
	pos = 0;
	j = ft_strlen(s) + 1;
	while (i < j)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + pos);
		}
		pos++;
		i++;
	}
	return (0);
}
