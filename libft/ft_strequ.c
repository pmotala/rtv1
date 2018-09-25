/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:44:41 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/05 09:06:21 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	if (!s1 || !s2)
		return (0);
	while (p1[i])
	{
		if (p1[i] != p2[i])
			return (0);
		i++;
	}
	if (p1[i] != p2[i])
		return (0);
	return (1);
}
