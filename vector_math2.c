/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:47:11 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:18:45 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect3		vect_subtract(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3 subt_vect;

	subt_vect.x = v1->x - v2->x;
	subt_vect.y = v1->y - v2->y;
	subt_vect.z = v1->z - v2->z;
	return (subt_vect);
}

t_vect3		vect_scale(t_vect3 *v1, double t)
{
	t_vect3 mult_vect;

	mult_vect.x = v1->x * t;
	mult_vect.y = v1->y * t;
	mult_vect.z = v1->z * t;
	return (mult_vect);
}

t_vect3		negative(t_vect3 *inst)
{
	t_vect3 neg;

	neg.x = inst->x * -1;
	neg.y = inst->y * -1;
	neg.z = inst->z * -1;
	return (neg);
}

t_vect3		new_vect3(double x, double y, double z)
{
	t_vect3 new_vect;

	new_vect.x = x;
	new_vect.y = y;
	new_vect.z = z;
	return (new_vect);
}

t_vect3		empty_vect3(void)
{
	t_vect3 new_vect;

	new_vect.x = 0;
	new_vect.y = 0;
	new_vect.z = 0;
	return (new_vect);
}
