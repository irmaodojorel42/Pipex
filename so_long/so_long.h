/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:53:39 by root              #+#    #+#             */
/*   Updated: 2024/02/01 16:25:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//////////// STRUCTS  //////////////
typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_picture
{
	void		*collectable;
	void		*wall;
	void		*player;
	void		*player2;
	void		*floor;
	void		*exit;
	void		*exit2;
	void		*enemy;
	void		*enemy2;
}				t_picture;

typedef struct s_main
{
	void		*win;
	char		**map;
	int			larg;
	int			altura;
	void		*mlx;
	int			moves_counter;
	int			col;
	int			change;
	t_player	player;
	t_picture	picture;
}				t_main;

///////////// VALIDATION //////////

void			map_paredes(t_main *main);
void			map_rectangle(t_main *main);
void			map_caracteres(t_main *main);
void			map_validate(t_main *main);
////////// MAPS ////////////

int				map_caracteres_valids(char *s);
char			**save_map(char **map, int fd);
void			check_map(char **av, t_main *main);

///////////// CONTROLS ////////////
int				key_hook(int keycode, t_main *main);
int				read_esc(int keycode, t_main *main);
void			verification_moves(t_main *m, int x, int y);
int				ft_strlen_sl(const char *s);

////////////// IMAGENS //////////////
void			image_inicialize(t_main *main);
int				render_image(t_main *main);
void			util_image(t_main *main, int x, int y);


///////////  MAIN //////////
int				end(t_main *main);
void			free_map(char **m);

////////// ALGORITMO  /////////////
int				algoritmo(int x, int y, char **map_copy, int col, t_main *main);
char			**copy_map(t_main *main);
void			check_map_alg(t_main *main, char **copy_map_temp);

#endif