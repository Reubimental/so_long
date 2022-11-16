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

#include "so_long.h"

t_entity	init_entities(void *mlx)
{
	t_entity	entity;

	init_player(&entity, mlx);
	init_enemy(&entity, mlx);
	init_item(&entity, mlx);
	init_exit(&entity, mlx);
	return (entity);
}

t_walls	init_walls(void *mlx)
{
	t_walls	wall;

	init_wall(&walls, mlx);
	return (wall);
}