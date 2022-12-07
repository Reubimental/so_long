#include "../../so_long.h"

int	check_c(char c, t_map *map, int col, int row)
{
	switch (c)
	{
		case 'P':
			map->valid.player_count += 1;
			map->player_pos.x = col;
			map->player_pos.y = row - 1;
			map->player_pos_reset.x = col;
			map->player_pos_reset.y = row - 1;
			return (1);
		case 'E':
			map->valid.exit_count += 1;
			return (1);
		case 'C':
			map->valid.consumable_count += 1;
			return (1);
		case '1':
		case '0':
			return (1);
		default:
			return (0);
	}
}
