/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:26:37 by pmotala           #+#    #+#             */
/*   Updated: 2018/09/25 10:18:52 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		read_file(char *path, t_mlx *mlx)
{
	char	*line;

	mlx->file = ft_strnew(0);
	mlx->fd = open(path, O_RDONLY);
	if (mlx->fd > 0)
	{
		while ((get_next_line(mlx->fd, &line)) > 0)
		{
			mlx->file = ft_strjoin_free(mlx->file, line, 1);
			mlx->file = ft_strjoin_free(mlx->file, "*", 1);
			free((void *)line);
		}
	}
	else
		return (-1);
	if (mlx->file != NULL && ft_strlen(mlx->file) != 0)
		close(mlx->fd);
	else
		return (-1);
	return (0);
}

int		init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "RTV1");
	init_image(mlx);
	mlx->objects = NULL;
	mlx->lights = NULL;
	if (parse(mlx) != 0)
	{
		ft_putendl("ERROR DURING READ!\n");
		return (-1);
	}
	free((void *)mlx->file);
	ft_strdel(mlx->scene);
	mlx->material.spec = 1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	(void)argv;
	if (argc == 2)
	{
		if ((read_file(argv[1], &mlx)) == -1)
		{
			free((void *)mlx.file);
			ft_putendl("ERROR DURING READ!\n");
			return (0);
		}
		if (init_mlx(&mlx) == -1)
			return (0);
	}
	else
	{
		ft_putendl("ERROR!: Requires a Scene File\n");
		return (0);
	}
	if (mlx_expose_hook(mlx.win, &expose_hook, &mlx) == -1)
		ft_putendl("ERROR DURING RAYTRACING!\n");
	mlx_hook(mlx.win, 2, 0, &key_press, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
