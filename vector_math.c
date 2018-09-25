/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:28:47 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:18:39 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vector_length(t_vect3 *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

void		normalize_vect(t_vect3 *v)
{
	double len;

	len = 1 / vector_length(v);
	if (len > 0)
	{
		v->x *= len;
		v->y *= len;
		v->z *= len;
	}
}

double		dot(t_vect3 *v1, t_vect3 *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

t_vect3		cross(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3 cross_vect;

	cross_vect.x = v1->y * v2->z - v1->z * v2->y;
	cross_vect.y = v1->z * v2->x - v1->x * v2->z;
	cross_vect.z = v1->x * v2->y - v1->y * v2->x;
	return (cross_vect);
}

t_vect3		vect_add(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3 add_vect;

	add_vect.x = v1->x + v2->x;
	add_vect.y = v1->y + v2->y;
	add_vect.z = v1->z + v2->z;
	return (add_vect);
}
