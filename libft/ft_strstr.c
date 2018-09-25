/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:33:26 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/01 11:25:16 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		t;
	int		pos;

	i = 0;
	t = 0;
	while (needle[t] != '\0')
		t++;
	if (t == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		pos = 0;
		while (needle[pos] == haystack[i + pos])
		{
			if ((pos) == (t - 1))
				return (((char *)haystack) + i);
			pos++;
		}
		i++;
	}
	return (0);
}
