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

			/* This struct will check that there is at least 1 Player, 1 Exit, 1 Consumable, and the Map is valid. */
			/* If any of these values are 0, the game will return an Error with the pertinent information. */
typedef struct	s_valid
{
	int	player_count;
	int	exit_count;
	int	consumable_count;
	int	valid_map;
}	t_valid;

			/* This struct tracks the image data for elements of the game */
typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

			/* This struct displays the sprite of an entity when said entity is facing a certain direction */
typedef struct s_direction
{
	t_image	up;
	t_image	down;
	t_image	left;
	t_image	right;
}	t_direction;

			/* This struct tracks different information that the player may find interesting. */
			/* Tracked data includes: */
			/* *How long they have taken since the map was created in Seconds */
			/* *How many enemies are currently on the map */
			/* *How many consumables have been collected */
			/* *How many steps have been taken */
typedef struct	s_counter
{
	int	time;
	int	enemies;
	int	items_consumed;
	int	steps_taken;
}	t_counter;

			/* This struct contains the x and y coordinates for anything that needs it */
typedef struct	s_position
{
	int	x;
	int	y;
}	t_position;

			/* This struct simply contains data for walls */
			/* I found that walls were different enough to entities to need their own struct */
			/* since they do not have a direction, size, and do not need to 'exist' */
typedef struct	s_walls
{
	t_image		sprite;
	t_position	position;
	t_position	size;
}	t_walls;

			/* This struct stores relevant data for entities, including: */
			/* *Position of the entity */
			/* *The direction the entity is facing */
			/* *The entities size */
			/* *The location is memory of the entities sprite */
			/* *How many of the entity still exists on the map */
typedef struct	s_e_data
{
	t_position			position;
	t_position			size;
	t_direction			direction;
	t_image				sprite;
	int					exists;
}	t_e_data;

			/* This struct holds the data for the map, the position of the elements within the map, and the games validity */
typedef struct	s_map
{
	t_position	player_pos;
	t_position	player_pos_reset;
	char		**map;
	char		**map_reset;
	int			line;
	int			column;
	t_valid		valid;
	int			item_reset;
}	t_map;

			/* This struct holds the data that differentiates the different entitity types */
typedef struct	s_entity
{
	t_e_data	player;
	t_e_data	enemy;
	t_e_data	item;
	t_e_data	exit;
}	t_entity;

			/* This struct holds the game data the brings the code to life for the player */
typedef struct	s_game
{
	t_entity	entity;
	t_map		map;
	t_walls		*walls;
	t_counter	counters;
}	t_game;

			/* The core of the program */
			/* This struct handles the gamestate and the existence and persistence of the Window, */
			/* and its associated memory */
typedef struct	s_root
{
	void	*mlx;
	void	*win;
	t_game	*game;
}	t_root;

#endif