#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 50
# define PATH_PU "./sprites/frog_standard_up.xpm"
# define PATH_PD "./sprites/frog_standard_down.xpm"
# define PATH_PL "./sprites/frog_standard_left.xpm"
# define PATH_PR "./sprites/frog_standard_right.xpm"
# define PATH_EL "./sprites/enemy_left.xpm"
# define PATH_EL_A "./sprites/enemy_left_anim.xpm"
# define PATH_ER "./sprites/enemy_right.xpm"
# define PATH_ER_A "./sprites/enemy_right_anim.xpm"
# define PATH_EX "./sprites/exit.xpm"
# define PATH_W "./sprites/wall.xpm"
# define PATH_P "./sprites/path.xpm"
# define PATH_I "./sprites/item.xpm"

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
# define KEY_RESET 114

# define K_NORMAL  "\x1B[0m"
# define K_RED  "\x1B[31m"
# define K_GREEN  "\x1B[32m"
# define K_YELLOW  "\x1B[33m"
# define K_BLUE  "\x1B[34m"
# define K_MAGENTA  "\x1B[35m"
# define K_CYAN  "\x1B[36m"
# define K_WHITE  "\x1B[37m"

# ifdef __APPLE__
#  include "mlx_opengl/mlx_int.h"
#  include "mlx_opengl/mlx_opengl.h"
#  include "mlx_opengl/mlx_new_window.h"
#  include "mlx_opengl/mlx.h"
# endif

# include "mlx_linux/mlx_int.h"
# include "mlx_linux/mlx.h"

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
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

enum tile_types
{
	TILE_PATH = 48, // '0'
	TILE_WALL = 49, // '1'
	TILE_ITEM = 67, // 'C'
	TILE_EXIT = 69, // 'E'	
	TILE_ENEMY = 70, // 'F'	
	TILE_PLAYER = 80, // 'P'
	TILE_TRAP = 84 // 'T'
};

enum t_facing
{
	FACING_UP = KEY_W,
	FACING_DOWN = KEY_S,
	FACING_LEFT = KEY_A,
	FACING_RIGHT = KEY_D
};

			/* This struct will check that there is at least 1 Player, 1 Exit, 1 Consumable, and the Map is valid. */
			/* If any of these values are 0, the game will return an Error with the pertinent information. */
typedef struct	s_count
{
	int	player_count;
	int	exit_count;
	int	consumable_count;
	int	enemy_count;
}	t_count;

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

			/* This struct contains the x and y coordinates for anything that needs it */
typedef struct	s_position
{
	int	x;
	int	y;
}	t_position;

			/* This struct simply contains data for walls */
			/* I found that walls were different enough to entities to need their own struct */
			/* since they do not have a direction, size, and do not need to 'exist' */
typedef struct	s_tile
{
	t_position	position;
	t_position	size;
	t_image		sprite;

}	t_tile;

			/* This struct stores relevant data for entities, including: */
			/* *Position of the entity */
			/* *The direction the entity is facing */
			/* *The entities size */
			/* *The location is memory of the entities sprite */
typedef struct	s_e_data
{
	t_position			position;
	t_position			size;
	t_direction			direction;
	t_image				sprite;
	enum	t_facing	facing;
}	t_e_data;

			/* This struct holds the data for the map, the position of the elements within the map, and the games validity */
typedef struct	s_map
{
	t_position	player_pos;
	t_position	player_pos_reset;
	char		**map;
	char		**map_reset;
	int			row;
	int			column;	
	int			item_reset;
	int			column_size;
	t_count		count;
	int			valid;
}	t_map;

			/* This struct holds the data that differentiates the different entitity types */
typedef struct	s_entity
{
	t_e_data	player;
	t_e_data	enemy;
	t_e_data	exit;
	t_e_data	animation;
	t_tile		item;
	t_tile		wall;
	t_tile		path;
}	t_entity;

			/* This struct holds the game data the brings the code to life for the player */
typedef struct	s_game
{
	t_entity	entity;
	t_map		map;
	double		refresh_rate; // replaced period because of clashes with time function
	int			end_game;
	int			steps_taken;
	int			animate;
}	t_game;

			/* The core of the program */
			/* This struct handles the gamestate and the existence and persistence of the Window, */
			/* and its associated memory */
typedef struct	s_root
{
	void		*mlx;
	void		*win;
	t_game		*game;
}	t_root;

char		**init_map(t_root *root,int argc, char **argv);
void		init_entities(t_root *root);
void		init_window(t_root *root);
void		init_player(t_entity *entity, void *mlx);
void		init_enemy(t_entity *entity, void *mlx);
void		init_item(t_entity *entity, void *mlx);
void		init_exit(t_entity *entity, void *mlx);
void		init_wall(t_entity *entity, void *mlx);
void		init_animation(t_entity *entity, void *mlx);
int			init_root(t_root *root, int argc, char **argv);
void		animate(t_root *root, t_position pos);
//void		init_enemies(t_root *root);
//void		roaming(t_root *root);
//void		roam_enemy(t_root *root, t_enemy *enemy);
//void		add_enemy(t_root *root, t_enemy new_enemy);
void		print_player(t_root *root, t_position pos);
void		print_map(t_root *root);
void		start_map(t_root *root, int argc, char **argv);
int			valid_map(int argc, char *map_file);
int			exit_game(t_root *root);
int			error_msg(char *message);
void		*nullptr_error(char *message);
void		warning(char *message);
int			update(t_root *roots);
char		*ft_itoa(int n);
char		**read_map(char *path, t_map *map);
int			rows(char *map_data, t_map *map);
int			counter(int fd, int row_count, int column_count, t_map *map);
void		free_map(char **map_data, t_map *map);
//void		free_enemies(t_root *root);
int			backup_map(t_map *map, char **map_data);
int			recover(t_map *map);
int			check_extension(char *str, char *extension);
char		*ft_strdup(const char *source);
void		verify(int valid, t_map *map);
int			check(char c, t_map *map, int col, int line);
void		check_last_line(char *row, t_map *map);
int			valid_entities(t_map *map);
int			check_c(char c, t_map *map, int col, int row);
int			check_wall(char c);
int			key_hook(int keycode, t_root *root);
void		kill_player(t_root *root);
int			verify_move(t_root *root, int row, int column, int keycode);
void		move_player(t_root *root, int row, int column, int keycode);
void		reset(t_root *root);
//void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif