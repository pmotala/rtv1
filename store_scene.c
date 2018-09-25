/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:26:58 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:19:47 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_add_lights(t_mlx *mlx, int *i, int j)
{
	t_object *light;

	light = &mlx->lights[mlx->num_lights];
	if (ft_strcmp(mlx->scene[*i + 1], "	{") != 0 &&
		ft_strcmp(mlx->scene[*i + 4], "	}") != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[*i + 2], "		colour (", 10) != 0 ||
		ft_strncmp(mlx->scene[*i + 3], "		position (", 12) != 0)
		return (-1);
	light->color.red = (double)ft_atoi_n(mlx->scene[*i + 2], &j);
	light->color.green = (double)ft_atoi_n(mlx->scene[*i + 2], &j);
	light->color.blue = (double)ft_atoi_n(mlx->scene[*i + 2], &j);
	j = 12;
	light->position.x = (double)ft_atoi_n(mlx->scene[*i + 3], &j);
	light->position.y = (double)ft_atoi_n(mlx->scene[*i + 3], &j);
	light->position.z = (double)ft_atoi_n(mlx->scene[*i + 3], &j);
	mlx->num_lights++;
	light->object_type = T_LIGHT;
	return (0);
}

int		ft_add_sphere(t_mlx *mlx, int *i, int j)
{
	t_object *sphere;

	sphere = &mlx->objects[mlx->num_objs];
	if (ft_strcmp(mlx->scene[*i + 1], "	{") != 0)
		return (-1);
	if (ft_col_pos(mlx, sphere, *i) != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[*i + 4], "		size", 6) != 0)
		return (-1);
	j = 6;
	sphere->size = (double)ft_atoi_n(mlx->scene[*i + 4], &j);
	if (ft_strcmp(mlx->scene[*i + 5], "	}") != 0)
		return (-1);
	sphere->index = mlx->num_objs;
	mlx->num_objs++;
	sphere->object_type = T_SPHERE;
	return (0);
}

int		ft_add_plane(t_mlx *mlx, int *i, int j)
{
	t_object *plane;

	plane = &mlx->objects[mlx->num_objs];
	if (ft_strcmp(mlx->scene[*i + 1], "	{") != 0 ||
		ft_strcmp(mlx->scene[*i + 5], "	}") != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[*i + 2], "		colour (", 10) != 0 ||
		ft_strncmp(mlx->scene[*i + 3], "		normal (", 10) != 0 ||
		ft_strncmp(mlx->scene[*i + 4], "		distance", 10) != 0)
		return (-1);
	plane->color.red = (double)ft_atoi_n(mlx->scene[*i + 2], &j);
	plane->color.green = (double)ft_atoi_n(mlx->scene[*i + 2], &j);
	plane->color.blue = (double)ft_atoi_n(mlx->scene[*i + 2], &j);
	j = 10;
	plane->normal.x = (double)ft_atoi_n(mlx->scene[*i + 3], &j);
	plane->normal.y = (double)ft_atoi_n(mlx->scene[*i + 3], &j);
	plane->normal.z = (double)ft_atoi_n(mlx->scene[*i + 3], &j);
	j = 10;
	plane->size = (double)ft_atoi_n(mlx->scene[*i + 4], &j);
	plane->index = mlx->num_objs;
	plane->object_type = T_PLANE;
	convert_rot(&plane->normal);
	mlx->num_objs++;
	return (0);
}

int		ft_add_cone(t_mlx *mlx, int *i, int j)
{
	t_object *cone;

	cone = &mlx->objects[mlx->num_objs];
	if (ft_strcmp(mlx->scene[*i + 1], "	{") != 0 ||
		ft_strcmp(mlx->scene[*i + 7], "	}") != 0)
		return (-1);
	if (ft_col_pos(mlx, cone, *i) != 0 ||
		ft_strncmp(mlx->scene[*i + 4], "		rotation (", 12) != 0)
		return (-1);
	j = 12;
	cone->rot.x = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 4], &j));
	cone->rot.y = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 4], &j));
	cone->rot.z = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 4], &j));
	if (ft_strncmp(mlx->scene[*i + 5], "		size", 6) != 0)
		return (-1);
	j = 6;
	cone->size = (double)ft_atoi_n(mlx->scene[*i + 5], &j);
	if (ft_strncmp(mlx->scene[*i + 6], "		angle", 7) != 0)
		return (-1);
	j = 7;
	cone->angle = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 6], &j));
	cone->index = mlx->num_objs;
	mlx->num_objs++;
	cone->object_type = T_CONE;
	return (0);
}

int		ft_add_cylinder(t_mlx *mlx, int *i, int j)
{
	t_object *cyl;

	cyl = &mlx->objects[mlx->num_objs];
	if (ft_strcmp(mlx->scene[*i + 1], "	{") != 0 ||
		ft_strcmp(mlx->scene[*i + 6], "	}") != 0)
		return (-1);
	if (ft_col_pos(mlx, cyl, *i) != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[*i + 4], "		rotation (", 12) != 0)
		return (-1);
	j = 12;
	cyl->rot.x = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 4], &j));
	cyl->rot.y = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 4], &j));
	cyl->rot.z = deg_to_rad((double)ft_atoi_n(mlx->scene[*i + 4], &j));
	if (ft_strncmp(mlx->scene[*i + 5], "		size", 6) != 0)
		return (-1);
	j = 6;
	cyl->size = (double)ft_atoi_n(mlx->scene[*i + 5], &j);
	cyl->index = mlx->num_objs;
	mlx->num_objs++;
	cyl->object_type = T_CYLINDER;
	return (0);
}
