/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenqu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:47:24 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/06 14:17:33 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (i < n && s1[i])
	{
		if (p1[i] != p2[i])
			return (0);
		i++;
	}
	if ((p1[i] != p2[i] && p1[i] == '\0') || n == 0)
		return (0);
	return (1);
}
