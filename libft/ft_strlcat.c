/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:50:00 by pmotala           #+#    #+#             */
/*   Updated: 2018/05/28 10:18:06 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = ft_strlen(dst);
	if (dstsize < k)
		return (dstsize + ft_strlen(src));
	else
	{
		while (k + j + 1 < dstsize && src[j] != '\0')
		{
			dst[k + j] = src[j];
			j++;
		}
		dst[k + j] = '\0';
		i = k + ft_strlen(src);
	}
	return (i);
}
