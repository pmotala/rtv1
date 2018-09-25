/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:48:08 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/06 14:48:09 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_n(char *str, int *i)
{
	int		s;
	int		res;

	res = 0;
	s = 1;
	while ((str[*i] < '0' || str[*i] > '9'))
		(*i)++;
	if (*i > 0 && str[(*i) - 1] == '-')
		(*i)--;
	if (str[*i] == '-')
		s = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (str[*i] <= '9' && str[*i] >= '0')
	{
		res = ((res * 10) + (str[*i] - '0'));
		(*i)++;
	}
	return (res * s);
}
