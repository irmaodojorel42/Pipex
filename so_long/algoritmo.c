/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:59:07 by root              #+#    #+#             */
/*   Updated: 2024/01/26 14:20:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	check_map_alg(t_main *main, char **copy_map_temp)
{
	if (copy_map_temp == NULL)
	{
		free_map(main->map);
		exit(write(1, "erro", 5));
	}
	if (algoritmo(main->player.x, main->player.y, copy_map_temp,
			main->col, main) == 1)
	{
		free_map(main->map);
		free_map(copy_map_temp);
		exit(write(1, "caminho nao valido\n", 20));
	}
	free_map(copy_map_temp);
}

char	**copy_map(t_main *main)
{
	char	**c_map;
	int		x;
	int		y;

	c_map = malloc(sizeof(char *) * (main->altura + 1));
	if (!c_map)
		return (NULL);
	x = 0;
	while (x < main->altura)
	{
		y = 0;
		c_map[x] = malloc(sizeof(char) * (ft_strlen(main->map[x]) + 1));
		if (!c_map)
			return (NULL);
		while (main->map[x][y] != '\0')
		{
			c_map[x][y] = main->map[x][y];
			y++;
		}
		c_map[x][y] = '\0';
		x++;
	}
	c_map[x] = NULL;
	return (c_map);
}

int	util_alg(int x, int y, char **map_copy, int col, t_main *main)
{
	if (map_copy[y][x] != '1' && map_copy[y][x] != 'z')
	{
		if (map_copy[y][x] == 'C')
		{	
			col--;
		}
		return (algoritmo(x, y, map_copy, col, main));
	}
	return (1);
}

int	algoritmo(int x, int y, char **map_copy, int col, t_main *main)
{
	static int	exit;
	static int	c;

	main->change = 1;
	if (col == 0)
	{
		c = 1;
	}
	if (map_copy[y][x] == 'E')
		exit = 1;
	if (c == 1 && exit == 1)
		return (0);
	map_copy[y][x] = 'z';
	if (util_alg(x, y - 1, map_copy, col, main) == 0)
		return (0);
	if (util_alg(x, y + 1, map_copy, col, main) == 0)
		return (0);
	if (util_alg(x + 1, y, map_copy, col, main) == 0)
		return (0);
	if (util_alg(x - 1, y, map_copy, col, main) == 0)
		return (0);
	return (1);
}