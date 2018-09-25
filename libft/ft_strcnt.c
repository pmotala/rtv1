/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:45:18 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/14 09:19:03 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcnt(const char *temp, char c)
{
	int		i;
	int		j;
	int		instring;

	i = 0;
	j = 0;
	instring = 0;
	if (!temp || !c)
		return (0);
	while (temp[i])
	{
		if (temp[i] == c && instring == 1)
			instring = 0;
		if (temp[i] != c && instring == 0)
		{
			j++;
			instring = 1;
		}
		i++;
	}
	return (j);
}
