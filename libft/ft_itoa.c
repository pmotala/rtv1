/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:48:39 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/01 10:52:16 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_c(int n)
{
	int		res;

	res = 0;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		res++;
		if (n < 10)
			return (res);
	}
	return (res);
}

static int	ft_sign_c(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		j;
	int		k;
	char	*str;

	k = 0;
	j = ft_size_c(n) + ft_sign_c(n);
	if ((str = (char *)malloc(sizeof(char) * (j + 2))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str[j + 1] = '\0';
	if (n < 0)
	{
		n = n * (-1);
		k = 1;
	}
	while (j >= 0)
	{
		str[j] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	if (k == 1)
		str[0] = '-';
	return (str);
}
