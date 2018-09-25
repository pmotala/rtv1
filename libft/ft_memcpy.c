/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:19:46 by pmotala           #+#    #+#             */
/*   Updated: 2018/05/21 14:19:48 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*buf;
	const char	*buf2;

	i = 0;
	buf = (char *)dst;
	buf2 = (const char *)src;
	while (i < n)
	{
		buf[i] = buf2[i];
		i++;
	}
	return (dst);
}
