#include "../../so_long.h"

int	check_c(char c, t_map *map, int col, int row)
{
	printf("%sFunction: check_c.%s\nFile: verify%s\nPosition = %d%s\n", K_MAGENTA, K_YELLOW, K_RED, map->player_pos.x, K_NORMAL);
	switch (c)
	{
		case 'P':
			map->count.player_count += 1;
			map->player_pos.x = col;
			map->player_pos.y = row - 1;
			printf("%sPlayer Located At:\n%sColumn: %d\n%sRow: %d%s\n", K_WHITE, K_GREEN, col, K_CYAN, row, K_NORMAL);
			map->player_pos_reset.x = col;
			map->player_pos_reset.y = row - 1;
			return (1);
		case 'E':
			map->count.exit_count += 1;
			return (1);
		case 'C':
			map->count.consumable_count += 1;
			return (1);
		case '1':
		case '0':
		case 'F':
			return (1);
		default:
			return (0);
	}
}
