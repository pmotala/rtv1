/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:25:31 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:19:06 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"\

void	draw_pixel(t_mlx *mlx, int x, int y, int colour)
{
	if (x < 0 || y < 0 || x >= WIDTH - 1 || y >= HEIGHT - 1)
		return ;
	*(int *)(mlx->image.data + ((x + y * WIDTH) * mlx->image.bpp / 8)) = colour;
}

void	init_image(t_mlx *mlx)
{
	if (!(mlx->image.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		return ;
	mlx->image.data = mlx_get_data_addr(mlx->image.img, &mlx->image.bpp,
						&mlx->image.linesize, &mlx->image.endian);
}

int		expose_hook(t_mlx *mlx)
{
	if (ft_draw(mlx) == -1)
		return (-1);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, 0, 0);
	return (0);
}
