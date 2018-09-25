/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:08:05 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/06 15:58:15 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	j = ft_strcnt(s, c);
	if (!(split = malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (j--)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		split[k] = ft_strsub(s, i, ft_wdlen(s, i, c));
		k++;
		i = i + ft_wdlen(s, i, c);
	}
	split[k] = NULL;
	return (split);
}
