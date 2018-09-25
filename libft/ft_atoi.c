/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <pmotala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:59:56 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/21 15:54:15 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(char c, int i)
{
	if (c == '-' || c == '+')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		c;
	int		res;

	i = 0;
	res = 0;
	s = 1;
	c = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		i++;
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '-')
		s = -1;
	i = sign(str[i], i);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = ((res * 10) + (str[i] - '0'));
		i++;
		c++;
	}
	return (res * s);
}
