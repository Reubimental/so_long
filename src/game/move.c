#include "../../so_long.h"

void	check_side(t_e_data player, int key)
{
	if (key == KEY_DOWN || key == KEY_S)
		player.facing = FACING_DOWN;
	else if (key == KEY_UP || key == KEY_W)
		player.facing = FACING_UP;
	else if (key == KEY_LEFT || key == KEY_A)
		player.facing = FACING_LEFT;
	else if (key == KEY_RIGHT || key == KEY_D)
		player.facing = FACING_RIGHT;
}

void	move_player(t_root *root, int row, int column, int keycode)
{
	int	x;
	int	y;
	int	valid;

	x = root->game->map.player_pos.x;
	y = root->game->map.player_pos.y;
	valid = verify_move(root, row, column, keycode);
	check_side(root->game->entity.player, keycode);
	if (root->game->end_game)
		kill_player(root);
	if (valid > 0)
	{
		if (root->game->map.map[row][column] == 'C')
			root->game->map.count.consumable_count--;
		root->game->map.map[y][x] = '0';
		root->game->map.map[row][column] = 'P';
		root->game->map.player_pos.y = row;
		root->game->map.player_pos.x = column;
		root->game->steps_taken++;
	}
}

int	verify_move(t_root *root, int row, int column, int keycode)
{
	if (root->game->map.map[row][column] == '1')
		return (-1);
	if (root->game->map.map[row][column] == 'E' &&
			root->game->map.count.consumable_count == 0)
		root->game->end_game = 1;
	if (root->game->map.map[row][column] == 'E')
		return (-1);
	if (root->game->end_game)
		return (-1);
	if (root->game->map.map[row][column] == 'F')
	{
		root->game->entity.player.facing = FACING_DOWN;
		reset(root);
		return (-1);
	}
	if (keycode != KEY_UP && keycode != KEY_DOWN && keycode != KEY_LEFT && keycode != KEY_RIGHT && keycode != KEY_W && keycode != KEY_A && keycode != KEY_S && keycode != KEY_D)
		return (-1);
	else
		return (1);
}