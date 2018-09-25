/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:25:46 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:19:57 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** The implicit surface formula of a plane:
** ((c + bt - p) . n) = 0
** t = - ((c - p).n)/(b . n)
** https://mrl.nyu.edu/~dzorin/cg05/lecture12.pdf
** check for zero in the denominator,
** because t has to be positive
*/

double		intersect_plane(t_ray *ray, t_object *obj, t_mlx *mlx)
{
	t_vect3	temp[2];

	T0 = dot(&ray->dir, &obj->normal);
	if (T0 == 0)
		return (-1);
	else
	{
		temp[0] = vect_scale(&obj->normal, obj->size);
		temp[0] = negative(&temp[0]);
		temp[1] = vect_add(&ray->origin, &temp[0]);
		T1 = dot(&obj->normal, &temp[1]);
		return (-1 * T1 / T0);
	}
	return (-1);
}

/*
** Substitute the Ray at distance formula -> R(t) = Origin + t * Direction, into
** Sphere surface formula |P^2 - C^2| = R^2.
** turn into form At^2 + Bt + C = 0
** https://mrl.nyu.edu/~dzorin/rend05/lecture2.pdf
** Solve Quadratic Equation:
** x = (-B +/- squareroot(B^2 - 4AC)) / 2A
*/

double		intersect_sphere(t_ray *ray, t_object *obj, t_mlx *mlx)
{
	double		discriminant;
	t_vect3		orig;

	orig = vect_subtract(&ray->origin, &obj->position);
	A = dot(&ray->dir, &ray->dir);
	B = 2 * (dot(&ray->dir, &orig));
	C = dot(&orig, &orig) - pow(obj->size, 2);
	discriminant = B * B - 4 * C;
	if (discriminant < 0)
		return (-1);
	T0 = (-B + sqrtf(discriminant)) / (2 * A) - 0.000001;
	T1 = (-B - sqrtf(discriminant)) / (2 * A) - 0.000001;
	if (T0 > T1)
		T0 = T1;
	return (T0);
}

/*
** Substitute the Ray at distance formula -> R(t) = Origin + t * Direction, into
** Sphere surface formula:
** (Q - Pa - (Va . (Q – Pa) ) Va)^2 - r2 = 0
** https://mrl.nyu.edu/~dzorin/rend05/lecture2.pdf
** turn into form AT^2 + BT + C = 0
** Solve Quadratic Equation:
** x = (-B +/- squareroot(B^2 - 4AC)) / 2A
*/

double		intersect_cylinder(t_ray *ray, t_object *obj, t_mlx *mlx)
{
	double		discriminant;

	mlx->dist = vect_subtract(&ray->origin, &obj->position);
	normalize_vect(&obj->rot);
	A = dot(&ray->dir, &ray->dir)
		- pow(dot(&ray->dir, &obj->rot), 2);
	B = 2 * (dot(&ray->dir, &mlx->dist)
			- (dot(&ray->dir, &obj->rot)
			* dot(&mlx->dist, &obj->rot)));
	C = dot(&mlx->dist, &mlx->dist)
		- pow(dot(&mlx->dist, &obj->rot), 2) - pow(obj->size, 2);
	discriminant = B * B - 4 * A * C;
	if (discriminant < 0)
		return (-1);
	T0 = (-B + sqrtf(discriminant)) / (2 * A) - 0.000001;
	T1 = (-B - sqrtf(discriminant)) / (2 * A) - 0.000001;
	if (T0 > T1)
		T0 = T1;
	return (T0);
}

/*
** Substitute the Ray at distance formula -> R(t) = Origin + t * Direction, into
** Cone surface formula:
** (P - C / ||P - C||) * V = cos^2theta.
** P is Surface Point, C is the tip of the cone,
** V is the direction of increasing radius,
** theta is the half angle between the axis and the surface.
** turn into form At^2 + Bt + C = 0
** https://mrl.nyu.edu/~dzorin/rend05/lecture2.pdf
** http://lousodrome.net/blog/light/2017/01/03/intersection-of-a-ray-and-a-cone/
** Solve Quadratic Equation:
** x = (-B +/- squareroot(B^2 - 4AC)) / 2A
*/

double		intersect_cone(t_ray *ray, t_object *obj, t_mlx *mlx)
{
	double		discriminant;
	double		height;

	mlx->dist = vect_subtract(&ray->origin, &obj->position);
	normalize_vect(&obj->rot);
	obj->size = size_adjuster(obj->size);
	A = dot(&ray->dir, &ray->dir) - (1 + pow(obj->angle, 2)) *
		pow(dot(&ray->dir, &obj->rot), 2);
	B = 2 * (dot(&ray->dir, &mlx->dist) - (1 + pow(obj->angle, 2)) *
		dot(&ray->dir, &obj->rot) * dot(&mlx->dist, &obj->rot));
	C = dot(&mlx->dist, &mlx->dist) - (1 + pow(obj->angle, 2))
		* pow(dot(&mlx->dist, &obj->rot), 2);
	discriminant = B * B - 4 * A * C;
	if (discriminant < 0)
		return (-1);
	T0 = (-B + sqrtf(discriminant)) / (2 * A) - 0.000001;
	T1 = (-B - sqrtf(discriminant)) / (2 * A) - 0.000001;
	T0 = (T0 > T1) ? T1 : T0;
	obj->hit_pos = (t_vect3){ray->origin.x + T0 * ray->dir.x - obj->position.x,
		ray->origin.y + T0 * ray->dir.y - obj->position.y,
		ray->origin.z + T0 * ray->dir.z - obj->position.z};
	height = -dot(&obj->hit_pos, &obj->rot);
	if (height < 0 || height > obj->size)
		return (-1);
	return (T0);
}

/*
** Checking if the Ray interset with any of the available objects in the scene
** Returns the object, but also stores the T value which is used in the formula
** R(t) = Ray->origin + t * Ray->direction, to discover the point of a ray, at
** a particular distance.
** The Object with the least distance is returned.
*/

t_object	*ft_intersections(t_ray *ray, t_mlx *mlx)
{
	t_object	*temp;
	double		dist;
	int			i;
	t_object	*obj;

	temp = NULL;
	i = -1;
	T = 80000.0;
	obj = mlx->objects;
	while (++i < mlx->num_objs)
	{
		dist = (TYPE_SPHERE) ? intersect_sphere(ray, &obj[i], mlx) : dist;
		dist = (TYPE_PLANE) ? intersect_plane(ray, &obj[i], mlx) : dist;
		dist = (TYPE_CYLINDER) ? intersect_cylinder(ray, &obj[i], mlx) : dist;
		dist = (TYPE_CONE) ? intersect_cone(ray, &obj[i], mlx) : dist;
		if (dist > 0.0001 && dist < T)
		{
			temp = &mlx->objects[i];
			T = dist;
		}
	}
	return (temp);
}
