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

void	init_game()
{
	root.game = malloc(sizeof(t_game));
}

int	key_hook(int keycode, t_root root)
{
	if (keycode == KEY_ESC)
	{
		exit_game();
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		root.game->player.direction = DIRECTION_UP;
		root.game->player.position.y -= 1;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		root.game->player.direction = DIRECTION_LEFT;
		root.game->player.position.x -= 1;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		root.game->player.direction = DIRECTION_DOWN;
		root.game->player.position.y += 1;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		root.game->player.direction = DIRECTION_RIGHT;
		root.game->player.position.x += 1;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int exit_game()
{
	mlx_clear_window(root.mlx, root.mlx_win);
	mlx_destroy_window(root.mlx, root.mlx_win);
	exit(0);
	return (0);
}

void create_player()
{
	root.game->player.width = 50;
	root.game->player.height = PLAYER_SIZE;
	root.game->player.image.img = mlx_new_image(root.mlx, root.game->player.width, root.game->player.height);
	root.game->player.image.addr = mlx_get_data_addr(root.game->player.image.img, &root.game->player.image.bits_per_pixel, &root.game->player.image.line_length, &root.game->player.image.endian);
	my_mlx_pixel_put(&root.game->player.image, 5, 5, 0x00FFFF00);
}

void create_background(t_data *bg)
{
	bg->img = mlx_new_image(root.mlx, 1366, 768);
	bg->addr = mlx_get_data_addr(bg->img, &bg->bits_per_pixel, &bg->line_length, &bg->endian);
	my_mlx_pixel_put(bg, 400, 400, 0x00FFFF00);
}

int	main(void)
{
	t_data	background;
	init_game();
	root.mlx = mlx_init();
	root.mlx_win = mlx_new_window(root.mlx, 1366, 768, "Hello World!");
	if (!root.mlx_win)
		return (0);
	create_background(&background);
	create_player();
	mlx_hook(root.mlx_win, EVENT_ON_DESTROY, 0, exit_game, &root);
	mlx_key_hook(root.mlx_win, key_hook, &root);
	//mlx_loop_hook(root.mlx);
	mlx_put_image_to_window(root.mlx, root.mlx_win, background.img, 0, 0);
	mlx_loop(root.mlx);
}
