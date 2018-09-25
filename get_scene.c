/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:26:49 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:19:30 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_col_pos(t_mlx *mlx, t_object *obj, int i)
{
	int j;

	j = 10;
	if (ft_strncmp(mlx->scene[i + 2], "		colour (", 10) != 0 ||
		ft_strncmp(mlx->scene[i + 3], "		position (", 12) != 0)
		return (-1);
	obj->color.red = (double)ft_atoi_n(mlx->scene[i + 2], &j);
	obj->color.green = (double)ft_atoi_n(mlx->scene[i + 2], &j);
	obj->color.blue = (double)ft_atoi_n(mlx->scene[i + 2], &j);
	j = 12;
	obj->position.x = (double)ft_atoi_n(mlx->scene[i + 3], &j);
	obj->position.y = (double)ft_atoi_n(mlx->scene[i + 3], &j);
	obj->position.z = (double)ft_atoi_n(mlx->scene[i + 3], &j);
	return (0);
}

int		ft_check_scene(t_mlx *mlx, int i)
{
	if (ft_strcmp(mlx->scene[0], "SCENE:") != 0)
		return (-1);
	if (ft_strcmp(mlx->scene[1], "{") != 0 ||
		ft_strcmp(mlx->scene[4], "}") != 0)
		return (-1);
	if (ft_strncmp(mlx->scene[2], "	camera_pos (", 13) != 0)
		return (-1);
	mlx->camera.origin.x = (double)ft_atoi_n(mlx->scene[2], &i);
	mlx->camera.origin.y = (double)ft_atoi_n(mlx->scene[2], &i);
	mlx->camera.origin.z = (double)ft_atoi_n(mlx->scene[2], &i);
	if (mlx->scene[2][i] != ')')
		return (-1);
	if (ft_strncmp(mlx->scene[3], "	camera_dir (", 13) != 0)
		return (-1);
	i = 13;
	mlx->camera.dir.x = (double)ft_atoi_n(mlx->scene[3], &i);
	mlx->camera.dir.y = (double)ft_atoi_n(mlx->scene[3], &i);
	mlx->camera.dir.z = (double)ft_atoi_n(mlx->scene[3], &i);
	if (mlx->scene[3][i] != ')')
		return (-1);
	return (0);
}

int		ft_store_objects(t_mlx *mlx, int i)
{
	int res;

	while (i++ < mlx->num_l - 1)
	{
		if (ft_strcmp(mlx->scene[i], "	OBJECT(light)") == 0)
			res = ft_add_lights(mlx, &i, 10);
		else if (ft_strcmp(mlx->scene[i], "	OBJECT(sphere)") == 0)
			res = ft_add_sphere(mlx, &i, 10);
		else if (ft_strcmp(mlx->scene[i], "	OBJECT(cone)") == 0)
			res = ft_add_cone(mlx, &i, 10);
		else if (ft_strcmp(mlx->scene[i], "	OBJECT(plane)") == 0)
			res = ft_add_plane(mlx, &i, 10);
		else if (ft_strcmp(mlx->scene[i], "	OBJECT(cylinder)") == 0)
			res = ft_add_cylinder(mlx, &i, 10);
		if (res == -1)
		{
			free(mlx->objects);
			free(mlx->lights);
			ft_putstr("ERROR IN SCENE FILE. CHECK FROM LINE: ");
			ft_putnbr(i + 4);
			ft_putstr(" AND FORWARD\n");
			return (-1);
		}
	}
	return (0);
}

int		ft_count_objs(t_mlx *mlx)
{
	int i;
	int num_obj;
	int num_lights;

	i = -1;
	num_obj = 0;
	num_lights = 0;
	while (++i < mlx->num_l)
	{
		if (ft_strcmp(mlx->scene[i], "	OBJECT(light)") == 0)
			num_lights += 1;
		else if (ft_strncmp(mlx->scene[i], "	OBJECT", 7) == 0)
			num_obj += 1;
	}
	mlx->lightcount = num_lights;
	return (num_obj);
}

int		parse(t_mlx *mlx)
{
	int			num_lines;
	int			i;

	mlx->scene = ft_strsplit(mlx->file, '*');
	num_lines = 0;
	while (mlx->scene[num_lines])
		num_lines++;
	mlx->num_l = num_lines;
	mlx->objcnt = ft_count_objs(mlx);
	mlx->num_lights = 0;
	mlx->num_objs = 0;
	i = 0;
	if (ft_check_scene(mlx, 13) == -1)
		return (-1);
	if (ft_strcmp(mlx->scene[5], "CONTENT:") != 0 ||
		ft_strcmp(mlx->scene[6], "{") != 0 ||
		ft_strcmp(mlx->scene[num_lines - 1], "}") != 0)
		return (-1);
	if (!(mlx->objects = (t_object *)malloc(sizeof(t_object) * mlx->objcnt)) ||
		!(mlx->lights = (t_object *)malloc(sizeof(t_object) * mlx->lightcount)))
		return (-1);
	if (ft_store_objects(mlx, 6) == -1 || mlx->objcnt != mlx->num_objs)
		return (-1);
	return (0);
}
