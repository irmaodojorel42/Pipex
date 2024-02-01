/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:57:46 by root              #+#    #+#             */
/*   Updated: 2024/01/29 09:26:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97

int	ft_strlen_sl(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0' && s[x] != '\n')
		x++;
	return (x);
}

void	verification_moves(t_main *m, int x, int y)
{
	if (m->map[y][x] == 'C')
	{
		m->col--;
		m->map[y][x] = '0';
		if (m->col == 0)
			m->change = 0;
	}
	else if (m->map[y][x] == 'E' && m->col == 0)
	{
		ft_putstr_fd("Parabens, você foi pra cuba!!!\n", 1);
		end(m);
	}
	else if (m->map[y][x] == 'X')
	{
		ft_putstr_fd("você foi pego!\n", 1);
		end(m);
	}
	m->player.y = y;
	m->player.x = x;
}


int	key_hook(int keycode, t_main *m)
{
	int	x;
	int	y;

	x = m->player.x;
	y = m->player.y;
	if (keycode == UP && m->map[y - 1][x] != '1' )
	{
		verification_moves(m, x, (y - 1));
		m->moves_counter++;
		ft_printf("count moves is %d\n", m->moves_counter);
	}
	else if (keycode == DOWN && m->map[y + 1][x] != '1')
	{
		verification_moves(m, x, (y + 1));
		m->moves_counter++;
		ft_printf("count moves is %d\n", m->moves_counter);
	}
	else if (keycode == RIGHT && m->map[y][x + 1] != '1')
	{
		verification_moves(m, (x + 1), y);
		m->moves_counter++;
		ft_printf("count moves is %d\n", m->moves_counter);
	}
	else if (keycode == LEFT && m->map[y][x - 1] != '1')
	{	
		verification_moves(m, (x - 1), y);
		m->moves_counter++;
		ft_printf("count moves is %d\n", m->moves_counter);
	}
	return (0);
}

int	read_esc(int keycode, t_main *main)
{
	if (keycode == 65307)
		end(main);
	return (0);
}