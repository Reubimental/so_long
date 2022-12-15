#include "../../so_long.h"

void	reset(t_root *root)
{
	recover(&root->game->map);
	root->game->map.player_pos.x = root->game->map.player_pos_reset.x;
	root->game->map.player_pos.y = root->game->map.player_pos_reset.y;
	root->game->end_game = 0;
	root->game->steps_taken = 0;
	root->game->entity.player.facing = FACING_DOWN;
}

void	kill_player(t_root *root)
{
	int	y;
	int	x;

	y = root->game->map.player_pos.y;
	x = root->game->map.player_pos.x;
	root->game->map.map[y][x] = '0';
	root->game->entity.player.facing = FACING_DOWN;
	print_map(root);
}

int	update(t_root *root)
{
	if (root->game->refresh_rate < 30)
	{
		root->game->refresh_rate += 0.1;
	}
	else if (root->game->end_game < 1)
	{
		print_map(root);
		//roaming(root);
		root->game->refresh_rate = 0;
		if (root->game->animate < 90)
			root->game->animate++;
		else
			root->game->animate = 0;
	}
	return (0);
}