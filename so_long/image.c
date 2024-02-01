/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:57:11 by root              #+#    #+#             */
/*   Updated: 2024/01/29 09:50:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_inicialize(t_main *main)
{
	int	i;

	main->picture.collectable = mlx_xpm_file_to_image(main->mlx,
			"./imagens/coletavel.xpm", &i, &i);
	main->picture.wall = mlx_xpm_file_to_image(main->mlx, "./imagens/wall.xpm",
			&i, &i);
	main->picture.player = mlx_xpm_file_to_image(main->mlx,
			"./imagens/player.xpm", &i, &i);
	main->picture.player2 = mlx_xpm_file_to_image(main->mlx,
			"./imagens/player2.xpm", &i, &i);
	main->picture.floor = mlx_xpm_file_to_image(main->mlx, "./imagens/chao.xpm",
			&i, &i);
	main->picture.exit = mlx_xpm_file_to_image(main->mlx, "./imagens/exit.xpm",
			&i, &i);
	main->picture.exit2 = mlx_xpm_file_to_image(main->mlx, "./imagens/exit2.xpm",
			&i, &i);
	main->picture.enemy = mlx_xpm_file_to_image(main->mlx, "./imagens/enemy.xpm",
			&i, &i);
	main->picture.enemy2 = mlx_xpm_file_to_image(main->mlx, "./imagens/enemy2.xpm",
			&i, &i);
}

void	util_image(t_main *main, int x, int y)
{
	if (main->map[y][x] == '1')
		mlx_put_image_to_window(main->mlx, main->win, main->picture.wall, (x
				* 64), (y * 64));
	else if (main->map[y][x] == 'P' || main->map[y][x] == '0')
		mlx_put_image_to_window(main->mlx, main->win, main->picture.floor, (x
				* 64), (y * 64));
	else if (main->map[y][x] == 'E')
	{
		if (main->change == 1)
			mlx_put_image_to_window(main->mlx, main->win, main->picture.exit, (x
					* 64), (y * 64));
		else
			mlx_put_image_to_window(main->mlx, main->win, main->picture.exit2, (x
					* 64), (y * 64));
	}
	else if (main->map[y][x] == 'C')
		mlx_put_image_to_window(main->mlx, main->win, main->picture.collectable,
			(x * 64), (y * 64));
	else if (main->map[y][x] == 'X')
	{
		if (main->change == 3)
			mlx_put_image_to_window(main->mlx, main->win, main->picture.enemy, (x
					* 64), (y * 64));
		else
			mlx_put_image_to_window(main->mlx, main->win, main->picture.enemy2, (x
					* 64), (y * 64));
	}
}

int	render_image(t_main *main)
{
	int	x;
	int	y;

	y = -1;
	while (main->map[++y] != NULL)
	{
		x = -1;
		while (main->map[y][++x] != '\0')
			util_image(main, x, y);
	}
	if(main->change == 1)
		mlx_put_image_to_window(main->mlx, main->win, main->picture.player,
			(main->player.x * 64), (main->player.y * 64));
	else if(main->change == 0)
		mlx_put_image_to_window(main->mlx, main->win, main->picture.player2,
			(main->player.x * 64), (main->player.y * 64));
	return (0);
}