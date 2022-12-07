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

t_entity	init_entities(void *mlx)
{
	t_entity	entity;

	init_player(&entity, mlx);
	init_enemy(&entity, mlx);
	init_item(&entity, mlx);
	init_exit(&entity, mlx);
	init_wall(&entity, mlx);
	return (entity);
}

static void print_entities(t_root *root, int row, int column)
{
	int	x;
	int	y;

	x = column * TILE_SIZE;
	y = row * TILE_SIZE;
	switch (root->game->map.map[row][column])
	{
		case TILE_EXIT:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.exit.sprite.img, x, y);
			break;
		case TILE_ITEM:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.item.sprite.img, x, y);
			break;
		case TILE_ENEMY:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.enemy.sprite.img, x, y);
			break;
		case TILE_PLAYER:
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.player.sprite.img, x, y);
			break;
	}
}

static void	print_tiles(t_root *root, int row, int column)
{
	int 		x;
	int			y;
	t_position	pos;

	x = column * TILE_SIZE;
	y = row * TILE_SIZE;
	pos.x = x;
	pos.y = y;
	switch (root->game->map.map[row][column])
	{ 
		case TILE_WALL: // if
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.wall.sprite.img, x, y);
			break;
		default: // else
			mlx_put_image_to_window(root->mlx, root->win, root->game->entity.path.sprite.img, x, y);
			break;
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
		mlx_string_put(root->mlx, root->win, 25, 25, 0xFFD700,
			"Steps Taken:");
		mlx_string_put(root->mlx, root->win, 120, 25, 0xFFD700,
			string);
		free(string);
		if (root->game->end_game)
			mlx_string_put(root->mlx, root->win, 150, 25, 0xFFD700,
				"Congratulations! You win!");
	}
}