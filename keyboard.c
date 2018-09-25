/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:26:09 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:18:59 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		win_close(void)
{
	exit(1);
	return (0);
}

int		key_press(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		win_close();
	else if (key == 13 || key == 126)
		mlx->camera.origin.y += 0.5;
	else if (key == 1 || key == 125)
		mlx->camera.origin.y -= 0.5;
	else if (key == 2 || key == 124)
		mlx->camera.origin.x += 0.5;
	else if (key == 0 || key == 123)
		mlx->camera.origin.x -= 0.5;
	else if (key == 6)
		mlx->camera.origin.z -= 0.5;
	else if (key == 7)
		mlx->camera.origin.z += 0.5;
	expose_hook(mlx);
	return (0);
}
