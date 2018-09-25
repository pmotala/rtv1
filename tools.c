/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:28:37 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:19:39 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	deg_to_rad(double angle)
{
	return (angle * M_PI / 180);
}

double	size_adjuster(double num)
{
	if ((int)num % 3 == 1)
		num += 2;
	else if ((int)num % 3 == 2)
		num += 1;
	return (num);
}

void	convert_rot(t_vect3 *rot)
{
	rot->x = ft_clamp(deg_to_rad(rot->x), -1.0, 1.0);
	rot->y = ft_clamp(deg_to_rad(rot->y), -1.0, 1.0);
	rot->z = ft_clamp(deg_to_rad(rot->z), -1.0, 1.0);
}

float	ft_clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return (value);
}

float	*ft_average(float *r, float *tab)
{
	r[0] += ft_clamp(tab[0], 0.0, 1.0);
	r[1] += ft_clamp(tab[1], 0.0, 1.0);
	r[2] += ft_clamp(tab[2], 0.0, 1.0);
	return (r);
}
