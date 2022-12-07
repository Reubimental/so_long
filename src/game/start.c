/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:56:02 by rkabzins          #+#    #+#             */
/*   Updated: 2022/11/21 15:56:05 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	start_map(t_map *map)
{
	map->row = 0;
	map->column = 0;
	map->item_reset = 0;
	map->valid.player_count = 0;
	map->valid.exit_count = 0;
	map->valid.consumable_count = 0;
	map->valid.valid_map = 1;
}

void	init_window(t_root *root)
{
	root->mlx = mlx_init();
	root->win = mlx_new_window(root->mlx, root->game->map.column * TILE_SIZE,
			root->game->map.row * TILE_SIZE, "so_long");
}

int	init_game(t_root *root, int argc, char **argv)
{
	t_map	map;

	start_map(&map);
	root->game->map = map;
	root->game->map.map = init_map(root, argc, argv);
	if (root->game->map.map == NULL)
		return (-1);
	init_window(root);
	root->game->entity = init_entities(root->mlx);
	root->game->entity.player.facing = FACING_DOWN;
	root->game->end_game = 0;
	root->game->refresh_rate = 0;
	print_map(root);
	return (1);
}