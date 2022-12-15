/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:28:05 by rkabzins          #+#    #+#             */
/*   Updated: 2022/11/03 19:28:08 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_root *root)
{
	int	row;
	int	col;

	row = root->game->map.player_pos.y;
	col = root->game->map.player_pos.x;
	switch (keycode)
	{
		case	KEY_ESC:
			exit_game(root);
			break;
		case	KEY_RESET:
			reset(root);
			break;
		case	KEY_W:
		case	KEY_UP:
			row--;
 			root->game->entity.player.facing = FACING_UP;
			break;
		case	KEY_A:
		case	KEY_LEFT:
 			root->game->entity.player.facing = FACING_LEFT;
			col--;
			break;
		case	KEY_S:
		case	KEY_DOWN:
			row++;
 			root->game->entity.player.facing = FACING_DOWN;
			break;
		case	KEY_D:
		case	KEY_RIGHT:
			col++;
 			root->game->entity.player.facing = FACING_RIGHT;
			break;
	}
	if (!root->game->end_game)
		move_player(root, row, col, keycode);
	return (1);
}

void	clear_game(t_root *root)
{
	free(root->game);
}

int exit_game(t_root *root)
{
	free_map(root->game->map.map, &root->game->map);
	mlx_clear_window(root->mlx, root->win);
	mlx_destroy_window(root->mlx, root->win);
	//free_enemies(root);
	clear_game(root);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root	root;

	if (init_root(&root, argc, argv) < 0)
		return (0);
	if (!root.win)
		return (0);
	print_map(&root);
	mlx_hook(root.win, EVENT_ON_DESTROY, 0, exit_game, (void *)&root);
	mlx_hook(root.win, EVENT_ON_KEYDOWN, (1L << 0), key_hook, (void *)&root);
	mlx_loop_hook(root.mlx, update, &root);
	mlx_loop(root.mlx);
	return (0);
}
