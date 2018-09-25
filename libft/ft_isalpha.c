/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:14:54 by pmotala           #+#    #+#             */
/*   Updated: 2018/05/28 13:21:45 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int		ft_isalpha(int c)
{
	if (c < 128 && c >= 0)
	{
		if ((unsigned char)c >= 65 && ((unsigned char)c <= 90))
			return (1);
		else if ((unsigned char)c >= 97 && ((unsigned char)c <= 122))
			return (1);
	}
	return (0);
}
