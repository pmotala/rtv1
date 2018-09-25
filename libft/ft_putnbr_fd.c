/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:39:01 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/06 14:27:34 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		k;
	char	str[12];

	ft_bzero(str, 12);
	i = ft_sizecheck(n) + ft_sign(n);
	k = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		while (i--)
		{
			if (n < 0)
			{
				n = n * -1;
				k = 1;
			}
			str[i] = (n % 10) + 48;
			n = n / 10;
		}
		if (k == 1)
			str[0] = '-';
		ft_putstr_fd(str, fd);
	}
}
