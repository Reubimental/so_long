#include "../../so_long.h"

int	check_c(char c, t_map *map, int col, int row)
{
	int	result;

	result = 1;
	switch (c)
	{
		case 'P':
			map->count.player_count += 1;
			map->player_pos.x = col;
			map->player_pos.y = row - 1;
			map->player_pos_reset.x = col;
			map->player_pos_reset.y = row - 1;
			break;
		case 'E':
			map->count.exit_count += 1;
			break;
		case 'C':
			map->count.consumable_count += 1;
			break;
		case '1':
		case '0':
			break;
		case 'F':
			map->count.enemy_count += 1;
			break;
		default:
			result = 0;
	}
	return (result);
}
