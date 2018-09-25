/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:26:28 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:20:40 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	*add_light_color(t_object *obj, t_object *light, float *tab,
						float distance_to_light)
{
	tab[3] = ft_clamp(tab[3] * 2 * distance_to_light, 0.0, 1.0);
	tab[0] += tab[3] + (ADD_RED);
	tab[1] += tab[3] + (ADD_GREEN);
	tab[2] += tab[3] + (ADD_BLUE);
	return (tab);
}

float	add_specularity(t_mlx *mlx, t_vect3 vect_at_light,
						float dist_to_light, float lumens)
{
	float	specularity;
	float	tmp;
	t_vect3	ref;

	specularity = 0.0;
	ref = vect_scale(&mlx->normal, (2 * dot(&mlx->normal, &vect_at_light)));
	ref = vect_subtract(&vect_at_light, &ref);
	if ((tmp = dot(&ref, &mlx->ray.dir)) > 0.0 && lumens > 0.15)
	{
		specularity = pow(tmp, 20) * 4 * dist_to_light;
		specularity = ft_clamp(specularity, 0.0, 1.0);
	}
	return (specularity);
}

t_vect3	ft_surface_normal(t_mlx *mlx, t_object *obj, t_vect3 pos)
{
	t_vect3	norm;
	t_vect3	temp[2];

	norm = (t_vect3){0, 0, 0};
	(void)mlx;
	if (obj->object_type == T_CONE)
	{
		temp[1] = vect_subtract(&pos, &obj->position);
		temp[0] = vect_scale(&obj->rot, dot(&obj->rot, &temp[1]));
		temp[0] = vect_scale(&temp[0], (1 + pow(tan(3), 2)));
		temp[1] = vect_subtract(&pos, &obj->position);
	}
	if (obj->object_type == T_CYLINDER)
	{
		temp[1] = vect_subtract(&pos, &obj->position);
		temp[0] = vect_scale(&obj->rot, dot(&obj->rot, &temp[1]));
	}
	norm = vect_subtract(&temp[1], &temp[0]);
	if (obj->object_type == T_PLANE)
		norm = obj->normal;
	if (obj->object_type == T_SPHERE)
		norm = vect_subtract(&pos, &obj->position);
	normalize_vect(&norm);
	return (norm);
}

int		add_shadow(t_mlx *mlx, t_object *obj, t_object *light)
{
	int		i;

	i = -1;
	mlx->shadow_ray.dir = vect_subtract(&light->position, &mlx->shadow_ray.dir);
	T = sqrtf(dot(&mlx->shadow_ray.dir, &mlx->shadow_ray.dir));
	normalize_vect(&mlx->shadow_ray.dir);
	while (++i < mlx->num_objs)
	{
		if (i != obj->index)
		{
			if (mlx->objects[i].object_type == T_CYLINDER)
				A = intersect_cylinder(&mlx->shadow_ray, &mlx->objects[i], mlx);
			else if (mlx->objects[i].object_type == T_CONE)
				A = intersect_cone(&mlx->shadow_ray, &mlx->objects[i], mlx);
			else if (mlx->objects[i].object_type == T_PLANE)
				A = intersect_plane(&mlx->shadow_ray, &mlx->objects[i], mlx);
			else if (mlx->objects[i].object_type == T_SPHERE)
				A = intersect_sphere(&mlx->shadow_ray, &mlx->objects[i], mlx);
			if (A > 0.0001 && A < T)
				return (1);
		}
	}
	return (0);
}

float	*ft_lighting(t_mlx *mlx, t_object *obj, float *tab)
{
	t_vect3	vect_at_light;
	float	dist_to_light;
	int		i;

	i = -1;
	mlx->shadow_ray.origin = (t_vect3){mlx->ray.origin.x + T * mlx->ray.dir.x,
		mlx->ray.origin.y + T * mlx->ray.dir.y,
		mlx->ray.origin.z + T * mlx->ray.dir.z};
	mlx->normal = ft_surface_normal(mlx, obj, mlx->shadow_ray.origin);
	while (++i < mlx->lightcount)
	{
		tab[3] = 0.2;
		vect_at_light = vect_subtract(&mlx->lights[i].position,
									&mlx->shadow_ray.origin);
		dist_to_light = ft_clamp((1.0 / sqrtf(sqrtf(dot(&vect_at_light,
								&vect_at_light)))), 0, 1.0);
		normalize_vect(&vect_at_light);
		if (add_shadow(mlx, obj, &mlx->lights[i]) == 0)
			tab[3] += ft_clamp(dot(&vect_at_light, &mlx->normal), 0, 1.0);
		tab = add_light_color(obj, &mlx->lights[i], tab, dist_to_light);
		tab[0] += (CONDITION) ? ADD_SPEC : 0.0;
		tab[1] += (CONDITION) ? ADD_SPEC : 0.0;
		tab[2] += (CONDITION) ? ADD_SPEC : 0.0;
	}
	return (tab);
}
