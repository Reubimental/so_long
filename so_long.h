/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:27:44 by rkabzins          #+#    #+#             */
/*   Updated: 2022/11/03 19:27:55 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx_int.h"
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include "src/gnl/get_next_line.h"

void	map();
typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	t_pos	player;
	t_pos	exit;
	t_pos	*collision;
	int		**map;
	int		height;
	int		width;
	int		player_up;
	int		player_down;
	int		player_left;
	int		player_right;
	int		player_collision;
	int		count_collision;
	int		count_exits;
	int		count_players;
	int		player_direction;
}	t_game;

typedef struct s_root
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
	t_img	*mlx_img;
	t_img	*player;
	t_img	*exit;
	t_img	*collision;
	t_img	*wall;
	t_img	*ground;
}	t_root;

#endif
