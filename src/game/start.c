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

void	init_game(t_game *game)
{
	game->refresh_rate = 0;
	game->end_game = 0;
	game->steps_taken = 0;
	game->animate = 0;
}

void	pos_count_structs(t_position *player_pos, t_position *player_pos_reset, t_count *count)
{
	player_pos->x = 0;
	player_pos->y = 0;
	player_pos_reset->x = 0;
	player_pos_reset->y = 0;
	count->player_count = 0;
	count->exit_count = 0;
	count->consumable_count = 0;
	count->enemy_count = 0;
}

void	map_structs(t_map *map)
{
	t_position	player_pos;
	t_position	player_pos_reset;
	t_count		count;

	pos_count_structs(&player_pos, &player_pos_reset, &count);
	map->player_pos = player_pos;
	map->player_pos_reset = player_pos_reset;
	map->count = count;
	map->row = 0;
	map->column = 0;
	map->item_reset = 0;
	map->column_size = 0;
	map->valid = 1;
}

void	start_map(t_root *root, int argc, char **argv)
{
	t_map	map;

	map_structs(&map);
	root->game->map = map;
	root->game->map.map = init_map(root, argc, argv);
}

void	init_window(t_root *root)
{
	root->mlx = mlx_init();
	root->win = mlx_new_window(root->mlx, root->game->map.column * TILE_SIZE,
			root->game->map.row * TILE_SIZE, "so_long");
}

int	init_root(t_root *root, int argc, char **argv)
{
	root->game = malloc(sizeof(t_game));
	init_game(root->game);
	start_map(root, argc, argv);
//	init_enemies(root);
	if (root->game->map.map == NULL)
		return (-1);
	init_window(root);
	init_entities(root);
	root->game->entity.player.facing = FACING_DOWN;
	print_map(root);
	return (1);
}