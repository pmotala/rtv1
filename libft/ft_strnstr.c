/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:21:40 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/06 14:16:16 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (needle[k])
		k++;
	if (k == 0)
		return ((char *)haystack);
	while (j < len && haystack[j])
	{
		i = 0;
		while ((needle[i] == haystack[j + i]) && (j + i <= len))
		{
			if (i == (k - 1))
				return ((char *)haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
