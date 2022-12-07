#include "../../so_long.h"

void	move_player(t_root *root, int row, int column, int keycode)
{
	int	x;
	int	y;
	int	valid;

	x = root->game->entity.player.position.x;
	y = root->game->entity.player.position.y;
	valid = verify_move(root, row, column, keycode);
	key_hook(keycode, root);
	if (root->game->end_game)
		kill_player(root);
	if (valid > 0)
	{
		if (root->game->map.map[row][column] == 'C')
			root->game->map.valid.consumable_count--;
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
		root->game->map.valid.consumable_count == 0)
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
	switch (keycode)
	{
		case	KEY_UP:
		case	KEY_W:
		case	KEY_LEFT:
		case	KEY_A:
		case	KEY_RIGHT:
		case	KEY_D:
		case	KEY_DOWN:
		case	KEY_S:
			return (1);
		default:
			return (-1);
	}
}