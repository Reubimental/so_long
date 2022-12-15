#include "../../so_long.c"

int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [3]){b, g, r});
}

unsigned char	get_r(int rgb)
{
	return (((unsigned char *)&rgb)[2]);
}

unsigned char	get_g(int rgb)
{
	return (((unsigned char *)&rgb)[1]);
}

unsigned char	get_b(int rgb)
{
	return (((unsigned char *)&rgb)[0]);
}

mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2, root->game->map.row * TILE_SIZE / 2, 0xFFD700,
					"Congratulations! You win! Press 'R' to Restart, or 'ESC' to exit the game!");