/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:46:56 by rkabzins          #+#    #+#             */
/*   Updated: 2022/12/02 15:47:02 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

void	verify(int valid, t_map *map)
{
	if (map->valid == 1)
		map->valid = valid;
}

void	check_last_line(char *row, t_map *map)
{
	int	i;
	int	entity;

	i = 0;
	while (i < map->column_size)
	{
		if (row[i] == '1')
			i++;
		else
		{
			map->valid = 0;
			break ;
		}
	}
	entity = valid_entities(map);
	if (entity == 0)
		map->valid = 0;
}

int	valid_entities(t_map *map)
{
	if (map->count.player_count != 1)
		return (error_msg("Please only include 1 Player in your map."));
	if (map->count.exit_count < 1)
		return (error_msg("Your map must have at least 1 exit."));
	if (map->count.consumable_count < 1)
		return (error_msg("Your map must have at least 1 consumable."));
	return (1);
}

int	check(char c, t_map *map, int col, int line)
{
	int	valid_c;

	valid_c = check_c(c, map, col, line);
	if (valid_c == 0 && c != '\n')
		return (error_msg("wrong character in the map"));
	if ((line == 1 || col == 0) && c != '\n')
		return (check_wall(c));
	if ((map->column_size == col) && c != '\n')
		return (check_wall(c));
	return (1);
}
