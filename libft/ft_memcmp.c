/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:46:07 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/01 10:32:15 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*buf1;
	unsigned const char	*buf2;
	size_t				i;

	i = 0;
	buf1 = (unsigned const char *)s1;
	buf2 = (unsigned const char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	else
	{
		while (i < n)
		{
			if (buf1[i] != buf2[i])
				return (buf1[i] - buf2[i]);
			i++;
		}
	}
	return (0);
}
