/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:27:06 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:19:18 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			check_window(double *px, double *py, int x, int y)
{
	double			angle;

	angle = 2.0;
	if (WIDTH > HEIGHT)
	{
		*px = -(2 * (x + 0.5) / (double)WIDTH - 1) * ASPECT;
		*py = (1 - 2 * (y + 0.5) / (double)HEIGHT);
	}
	if (WIDTH == HEIGHT)
	{
		*px = (WIDTH - (double)x * 2.0) / HEIGHT;
		*py = (HEIGHT - (double)y * 2.0) / WIDTH;
	}
}

static float	*ft_set_ray(t_mlx *mlx, float *tab, double x, double y)
{
	double			px;
	double			py;
	double			angle;

	angle = 2.0;
	check_window(&px, &py, x, y);
	K = vect_subtract(&mlx->camera.dir, &mlx->camera.origin);
	normalize_vect(&K);
	I = cross(&K, &(t_vect3){0.0, 1.0, 0.0});
	normalize_vect(&I);
	J = cross(&I, &K);
	mlx->ray.dir = (t_vect3){	px * I.x + py * J.x + angle * K.x,
		px * I.y + py * J.y + angle * K.y,
		px * I.z + py * J.z + angle * K.z};
	mlx->ray.origin = (t_vect3){mlx->camera.origin.x,
		mlx->camera.origin.y,
		mlx->camera.origin.z};
	normalize_vect(&mlx->ray.dir);
	ft_fzero(tab, 4);
	return (tab);
}

static int		ft_raytrace(t_mlx *mlx, double x, double y)
{
	t_object		*temp;
	float			*tab;
	float			r[3];
	unsigned int	color;

	if (!(tab = (float *)malloc(sizeof(float) * 4)))
		return (-1);
	ft_fzero(r, 3);
	ft_set_ray(mlx, tab, x, y);
	if ((temp = ft_intersections(&mlx->ray, mlx)))
		tab = ft_lighting(mlx, temp, tab);
	ft_average(r, tab);
	color = (((int)(r[0] / 1.0 * 255) & 0xff) << 16) +
		(((int)(r[1] / 1.0 * 255) & 0xff) << 8) +
		((int)(r[2] / 1.0 * 255) & 0xff);
	draw_pixel(mlx, mlx->intx, mlx->inty, color);
	free(tab);
	return (0);
}

int				ft_draw(t_mlx *mlx)
{
	double			x;
	double			y;

	y = 0.0;
	x = 0.0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			mlx->intx = (int)x;
			mlx->inty = (int)y;
			ft_raytrace(mlx, x, y);
			x += 1.0;
		}
		y += 1.0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, 0, 0);
	return (0);
}
