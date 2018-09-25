/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:19:55 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/05 09:03:22 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	while (s[j] != '\0')
		j++;
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (i <= (j + 1))
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[j] = '\0';
	return (str);
}
