/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:46:14 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 09:58:47 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int num)
{
	int		i[3];
	char	*str;

	i[0] = -1;
	i[1] = -1;
	if (!s1 || !s2)
		return (NULL);
	i[2] = (ft_strlen(s1) + ft_strlen(s2));
	if (!(str = (char *)malloc(sizeof(str) * (i[2] + 1))))
		return (NULL);
	while (s1[++i[0]])
	{
		str[i[0]] = s1[i[0]];
	}
	while (s2[++i[1]])
	{
		str[i[0]] = s2[i[1]];
		i[0]++;
	}
	str[i[0]] = '\0';
	if (num == 1)
		free((void *)s1);
	else if (num == 2)
		free((void *)s2);
	return (str);
}
