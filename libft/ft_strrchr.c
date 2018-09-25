/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:15:28 by pmotala           #+#    #+#             */
/*   Updated: 2018/05/21 11:15:31 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)s;
	i = 0;
	j = ft_strlen(s);
	while (i <= j)
	{
		if (s[j] == c)
		{
			return (&ret[j]);
		}
		j--;
	}
	return (0);
}
