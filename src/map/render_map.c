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

void	init_entities(t_root *root)
{
	t_entity	entity;
	t_e_data	player;
	t_e_data	enemy;
	t_e_data	exit;
	t_e_data	animation;
	t_tile		item;
	t_tile		wall;
	t_tile		path;

	entity_location(&player);
	entity_location(&animation);
	entity_location(&enemy);
	entity_location(&exit);
	tile_location(&item);
	tile_location(&wall);
	tile_location(&path);
	root->game->entity.player = player;
	root->game->entity.enemy = enemy;
	root->game->entity.animation = animation;
	root->game->entity.item = item;
	root->game->entity.exit = exit;
	root->game->entity.wall = wall;
	root->game->entity.path = path;
	init_player(&entity, root->mlx);
	init_enemy(&entity, root->mlx);
	init_item(&entity, root->mlx);
	init_exit(&entity, root->mlx);
	init_wall(&entity, root->mlx);
	init_animation(&entity, root->mlx);
	root->game->entity = entity;
}

void	print_player(t_root *root, t_position pos)
{
	switch (root->game->entity.player.facing)
	{
		case FACING_UP:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.up.img, pos.x, pos.y);
			break ;
		case FACING_LEFT:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.left.img, pos.x, pos.y);
			break ;
		case FACING_RIGHT:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.right.img, pos.x, pos.y);
			break ;
		default:
		mlx_put_image_to_window(root->mlx, root->win,
			root->game->entity.player.direction.down.img, pos.x, pos.y);
			break ;
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
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.exit.sprite.img, x, y);
			break;
		case TILE_ITEM:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.item.sprite.img, x, y);
			break;
		case TILE_ENEMY:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
			if (root->game->animate <= 90 && root->game->animate >= 45)
				mlx_put_image_to_window(root->mlx, root->win, root->game->entity.enemy.sprite.img, pos.x, pos.y);
			else
				mlx_put_image_to_window(root->mlx, root->win, root->game->entity.animation.direction.left.img, pos.x, pos.y);
			break;
		case TILE_PLAYER:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
			print_player(root, pos);
			break;
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
		case TILE_WALL:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.wall.sprite.img, x, y);
			break ;
		default:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
	}
}

void	print_map(t_root *root)
{
	int		row;
	int		column;
	char	*string;

	row = 0;
	while (row < root->game->map.row)
	{
		column = 0;
		while (column < root->game->map.column)
		{
			print_tiles(root, row, column);
			print_entities(root, row, column);
			column++;
		}
		row++;
		string = ft_itoa(root->game->steps_taken);
		mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 - 40, 25, 0xFFD700,
			"Steps Taken:");
		mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 + 40, 25, 0xFFD700,
			string);
		if (root->game->end_game)
		{
			mlx_clear_window(root->mlx, root->win);
			mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 - 50, root->game->map.row * TILE_SIZE / 2 - 25, 0xFFD700,
			"Steps Taken:");
			mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 + 30, root->game->map.row * TILE_SIZE / 2 - 25, 0xFFD700,
			string);
			mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 - 135, root->game->map.row * TILE_SIZE / 2 + 24, 0x960019,
					"Press 'R' to Restart, or 'ESC' to exit the game!");
			mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 - 135, root->game->map.row * TILE_SIZE / 2 + 25, 0xFF0800,
					"Press 'R' to Restart, or 'ESC' to exit the game!");
			mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 - 75, root->game->map.row * TILE_SIZE / 2 + 1, 0xB200ED,
					"Congratulations! You win!");
			mlx_string_put(root->mlx, root->win, root->game->map.column * TILE_SIZE / 2 - 75, root->game->map.row * TILE_SIZE / 2, 0x8660CD,
					"Congratulations! You win!");
		}
		free(string);
	}
}