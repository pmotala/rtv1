/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:10:10 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/01 10:34:16 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buf;
	char	*buf2;
	size_t	i;

	i = -1;
	buf = (char *)dst;
	buf2 = (char *)src;
	if (buf2 < buf)
	{
		while (len--)
			buf[len] = buf2[len];
	}
	else
	{
		while (++i < len)
			buf[i] = buf2[i];
	}
	return (dst);
}
