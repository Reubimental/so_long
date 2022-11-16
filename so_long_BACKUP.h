/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:27:44 by rkabzins          #+#    #+#             */
/*   Updated: 2022/11/03 19:27:55 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32
# define KEY_ESC 65307
# define PLAYER_SIZE 50

# include "mlx_linux/mlx_int.h"
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include "src/gnl/get_next_line.h"

void	map();
int 	exit_game();

enum mlx_events
{
	EVENT_ON_KEYDOWN = 2,
	EVENT_ON_KEYUP = 3,
	EVENT_ON_MOUSE = 4,
	EVENT_ON_MOUSEUP = 5,
	EVENT_ON_MOUSEMOVE = 6,
	EVENT_ON_EXPOSE = 12,
	EVENT_ON_DESTROY = 17
};

enum t_player_direction
{
	DIRECTION_UP = 0,
	DIRECTION_DOWN = 1,
	DIRECTION_LEFT = 2,
	DIRECTION_RIGHT = 3
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_direction
{
	t_data	down;
	t_data	up;
	t_data	left;
	t_data	right;
}	t_direction;

typedef struct	s_entity
{
	t_data		wall;
	t_data		exit;
	t_direction	enemy;
	t_data		item;
}				t_entity;

typedef struct s_player
{
	t_pos						position;
	t_pos						size;
	enum	t_player_direction	direction;
	t_data						image;
}	t_player;

typedef struct s_game
{
	t_entity			entity;
	t_pos				exit;
	t_pos				*walls;
	int					**map;
	int					height;
	int					width;
	int					player_collision;
	int					count_collision;
	int					count_exits;
	int					count_players;
}	t_game;

typedef struct s_root
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
	/*t_img	*mlx_img;
	t_img	*player;
	t_img	*exit;
	t_img	*collision;
	t_img	*wall;
	t_img	*ground;*/
}	t_root;

#endif
