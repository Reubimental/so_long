/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:31:54 by rkabzins          #+#    #+#             */
/*   Updated: 2022/11/16 22:31:57 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	entity_location(t_e_data *entity)
{
	t_position	position;
	t_position	size;

	size.x = TILE_SIZE;
	size.y = TILE_SIZE;
	position.x = 0;
	position.y = 0;
	entity->position = position;
	entity->size = size;
}

void	tile_location(t_tile *entity)
{
	t_position	position;
	t_position	size;

	size.x = TILE_SIZE;
	size.y = TILE_SIZE;
	position.x = 0;
	position.y = 0;
	entity->position = position;
	entity->size = size;
}

void	init_entities(t_root *root, void *mlx)
{
	t_entity	entity;
	t_e_data	player;
	t_e_data	enemy;
	t_e_data	exit;
	t_tile		item;
	t_tile		wall;
	t_tile		path;

	entity_location(&player);
	entity_location(&enemy);
	entity_location(&exit);
	tile_location(&item);
	tile_location(&wall);
	tile_location(&path);
	root->game->entity.player = player;
	root->game->entity.enemy = enemy;
	root->game->entity.item = item;
	root->game->entity.exit = exit;
	root->game->entity.wall = wall;
	root->game->entity.path = path;
	init_player(&entity, mlx);
	init_enemy(&entity, mlx);
	init_item(&entity, mlx);
	init_exit(&entity, mlx);
	init_wall(&entity, mlx);
	root->game->entity = entity;
}

void	print_player(t_root *root, t_position pos)
{
	printf("%sFunction: print_player.%s\nFile: render_map%s\nPosition = %d%s\n", K_MAGENTA, K_YELLOW, K_RED, root->game->entity.player.position.x, K_NORMAL);
	switch (root->game->entity.player.facing)
	{
		case FACING_UP:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.up.img, pos.x, pos.y);
//			break ;
		case FACING_LEFT:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.left.img, pos.x, pos.y);
//			break ;
		case FACING_RIGHT:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.right.img, pos.x, pos.y);
//			break ;
		default:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.down.img, pos.x, pos.y);
//			break ;
	}
}

static void print_entities(t_root *root, int row, int column)
{
	int			x;
	int			y;
	t_position	pos;

	x = column * TILE_SIZE;
	y = row * TILE_SIZE;
	pos.x = x;
	pos.y = y;
	switch (root->game->map.map[row][column])
	{
		case TILE_EXIT:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.exit.sprite.img, x, y);
//			break;
		case TILE_ITEM:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.item.sprite.img, x, y);
//			break;
		case TILE_ENEMY:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.enemy.sprite.img, x, y);
//			break;
		case TILE_PLAYER:
			print_player(root, pos);
//			break;
	}
}

static void	print_tiles(t_root *root, int row, int column)
{
	int 		x;
	int			y;

	x = column * TILE_SIZE;
	y = row * TILE_SIZE;
	switch (root->game->map.map[row][column])
	{ 
		case TILE_WALL: // if
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.wall.sprite.img, x, y);
//			break;
		default: // else
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
//			break;
	}
}

void	print_map(t_root *root)
{
	int		row;
	int		column;
	char	*string;

	row = 0;
	printf("%sFunction: print_map.%s\nFile: render_map%s\nPosition = %d%s\n", K_MAGENTA, K_YELLOW, K_RED, root->game->map.player_pos.x, K_NORMAL);
	while (row < root->game->map.row)
	{
	printf("%sWhile Part 1.%s\n", K_GREEN, K_NORMAL);
	printf("%sRow: %d%s\n", K_GREEN, row + 1, K_NORMAL);
		column = 0;
		while (column < root->game->map.column)
		{
		printf("%sWhile Part 2.%s\n", K_GREEN, K_NORMAL);
		printf("%sColumn: %d%s\n", K_GREEN, column + 1, K_NORMAL);
			print_tiles(root, row, column);
			print_entities(root, row, column);
			column++;
		}
		row++;
		string = ft_itoa(root->game->steps_taken);
		printf("%sWhile Part 3.%s\n", K_GREEN, K_NORMAL);
		mlx_string_put(root->mlx, root->win, 25, 25, 0xFFD700,
			"Steps Taken:");
		mlx_string_put(root->mlx, root->win, 120, 25, 0xFFD700,
			string);
		free(string);
		if (root->game->end_game)
			mlx_string_put(root->mlx, root->win, 300, 175, 0xFFD700,
					"Congratulations! You win!");
	}
	printf("%sRow = %d\n%sGlobal Row = %d%s\n", K_MAGENTA, row, K_YELLOW, root->game->entity.player.position.x, K_NORMAL);
}