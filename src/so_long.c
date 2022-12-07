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

t_root	root;

int	key_hook(int keycode, t_root *root)
{
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
			root->game->entity.player.facing = FACING_UP;
			root->game->entity.player.position.y -= 1;
			break;
		case	KEY_A:
		case	KEY_LEFT:
			root->game->entity.player.facing = FACING_LEFT;
			root->game->entity.player.position.x -= 1;
			break;
		case	KEY_S:
		case	KEY_DOWN:
			root->game->entity.player.facing = FACING_DOWN;
			root->game->entity.player.position.y += 1;
			break;
		case	KEY_D:
		case	KEY_RIGHT:
			root->game->entity.player.facing = FACING_RIGHT;
			root->game->entity.player.position.x += 1;
			break;
	}
	if (!root->game->end_game)
		move_player(root, root->game->entity.player.position.x,
			root->game->entity.player.position.y, keycode);
	return (1);
}

int exit_game(t_root *root)
{
	free_map(root->game->map.map, &root->game->map);
	mlx_clear_window(root->mlx, root->win);
	mlx_destroy_window(root->mlx, root->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root	root;

	if (init_game(&root, argc, argv) < 0)
		return (0);
	root.mlx = mlx_init();
	root.win = mlx_new_window(root.mlx, root.game->map.column * TILE_SIZE,
			root.game->map.row * TILE_SIZE, "so_long");
	if (!root.win)
		return (0);
	print_map(&root);
	mlx_hook(root.win, EVENT_ON_DESTROY, 0, exit_game, &root);
	mlx_key_hook(root.win, key_hook, &root);
	mlx_loop_hook(root.mlx, update, &root);
	mlx_loop(root.mlx);
}
