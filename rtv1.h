/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:28:27 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:20:32 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define HEIGHT 720
# define WIDTH 720

# define FOV tan(deg_to_rad(90 * 0.5))
# define ASPECT (double)WIDTH / (double)HEIGHT
# define PI 3.14159265

# define I mlx->ijk[0]
# define J mlx->ijk[1]
# define K mlx->ijk[2]

# define A mlx->abc[0]
# define B mlx->abc[1]
# define C mlx->abc[2]

# define T mlx->t[0]
# define T0 mlx->t[1]
# define T1 mlx->t[2]

# define TYPE_SPHERE mlx->objects[i].object_type == T_SPHERE
# define TYPE_PLANE mlx->objects[i].object_type == T_PLANE
# define TYPE_CYLINDER mlx->objects[i].object_type == T_CYLINDER
# define TYPE_CONE mlx->objects[i].object_type == T_CONE

# define ADD_RED obj->color.red / 255) * (light->color.red / 255
# define ADD_GREEN obj->color.green / 255) * (light->color.green / 255
# define ADD_BLUE obj->color.blue / 255) * (light->color.blue / 255

# define CONDITION mlx->material.spec == 1 && obj->object_type != T_PLANE
# define ADD_SPEC add_specularity(mlx, vect_at_light, dist_to_light, tab[3])

typedef struct	s_vect3
{
	double		x;
	double		y;
	double		z;
}				t_vect3;

typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			linesize;
	int			endian;
}				t_image;

typedef enum	e_obj_type
{
	T_CAMERA = -2,
	T_LIGHT = -1,
	T_SPHERE = 0,
	T_PLANE,
	T_CONE,
	T_CYLINDER,
}				t_obj_type;

typedef struct	s_color
{
	double		red;
	double		green;
	double		blue;
}				t_color;

typedef struct	s_material
{
	double		spec;
	double		ambient;
}				t_material;

typedef struct	s_object
{
	t_vect3		origin;
	t_vect3		position;
	t_vect3		rot;
	t_vect3		rot_rad;
	t_vect3		normal;
	t_vect3		axis;
	t_obj_type	object_type;
	double		radius;
	double		size;
	double		height;
	t_color		color;
	int			index;
	t_vect3		hit_pos;
	double		angle;
}				t_object;

typedef struct	s_ray
{
	t_vect3		origin;
	t_vect3		dir;
}				t_ray;

typedef struct	s_camera
{
	t_vect3		origin;
	t_vect3		dir;
	t_vect3		right;
	t_vect3		down;
}				t_camera;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			fd;
	t_image		image;
	int			objcnt;
	int			num_l;
	int			lightcount;
	int			num_lights;
	int			num_objs;
	int			selection;
	t_object	*objects;
	t_object	*scene_objects;
	t_object	*lights;
	t_vect3		normal;
	t_camera	camera;
	t_ray		ray;
	t_ray		shadow_ray;
	double		abc[3];
	double		t[3];
	int			index;
	t_material	material;
	int			cpt;
	t_vect3		ijk[3];
	double		cosine_ang;
	char		**scene;
	char		*file;
	int			intx;
	int			inty;
	t_vect3		dist;
	double		anti_aliasing;
}				t_mlx;

typedef struct	s_mlx_tab
{
	t_mlx		*mlx;
	int			i;
}				t_mlx_tab;

/*
**VECTOR MATH
*/
t_vect3			new_vect3(double x, double y, double z);
t_vect3			empty_vect3(void);
void			normalize_vect(t_vect3 *v);
t_vect3			vect_subtract(t_vect3 *v1, t_vect3 *v2);
double			dot(t_vect3 *v1, t_vect3 *v2);
t_vect3			vect_scale(t_vect3 *v1, double t);
t_vect3			new_vect3(double x, double y, double z);
t_vect3			cross(t_vect3 *v1, t_vect3 *v2);
double			vector_length(t_vect3 *v);
t_vect3			vect_add(t_vect3 *v1, t_vect3 *v2);
t_vect3			empty_vect3(void);
t_vect3			negative(t_vect3 *inst);

/*
**FUNCTIONS
*/
int				expose_hook(t_mlx *mlx);
void			draw_pixel(t_mlx *mlx, int x, int y, int colour);
void			init_image(t_mlx *mlx);

/*
**KEYBOARD
*/
int				key_press(int key, t_mlx *mlx);
int				win_close(void);

/*
**RAYTRACING
*/
void			raytracing(t_mlx *mlx);
int				ft_draw(t_mlx *mlx);

/*
**INITIALIZE OBJECTS FROM SCENE FILE
*/
int				ft_add_cone(t_mlx *mlx, int *i, int j);
int				ft_add_cylinder(t_mlx *mlx, int *i, int j);
int				ft_add_plane(t_mlx *mlx, int *i, int j);
int				ft_add_sphere(t_mlx *mlx, int *i, int j);
int				ft_col_pos(t_mlx *mlx, t_object *obj, int i);
int				ft_add_lights(t_mlx *mlx, int *i, int j);

/*
**GET OBJECTS FROM SCENE
*/
int				parse(t_mlx *mlx);
int				ft_count_objs(t_mlx *mlx);
int				ft_store_objects(t_mlx *mlx, int i);
int				ft_check_scene(t_mlx *mlx, int i);

/*
**LIGHTING
*/
float			*ft_lighting(t_mlx *mlx, t_object *obj, float *tab);

/*
**OBJECT INTERSECTIONS
*/
double			intersect_plane(t_ray *ray, t_object *obj, t_mlx *mlx);
double			intersect_sphere(t_ray *ray, t_object *obj, t_mlx *mlx);
double			intersect_cone(t_ray *ray, t_object *obj, t_mlx *mlx);
double			intersect_cylinder(t_ray *ray, t_object *obj, t_mlx *mlx);
t_object		*ft_intersections(t_ray *ray, t_mlx *mlx);

/*
**TOOLS
*/
float			*ft_average(float *r, float *tab);
float			ft_clamp(float value, float min, float max);
double			deg_to_rad(double angle);
void			convert_rot(t_vect3 *rot);
double			size_adjuster(double num);

#endif
