/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:57:11 by pmotala           #+#    #+#             */
/*   Updated: 2018/06/06 15:58:48 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			k;
	size_t			j;
	char			*str;

	i = 0;
	k = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[j])
		j++;
	k = j;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\0'))
		j--;
	if (i > 0 || j < k)
	{
		str = ft_strsub(s, i, ((j - i) + 1));
		return (str);
	}
	return (ft_strdup(s));
}
