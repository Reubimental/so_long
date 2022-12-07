#include "../../so_long.h"

int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			;
		else
			return (0);
	}
	return (1);
}

int	valid_map(int argc, char *map_file)
{
	if (argc == 1)
		return (error_msg("Please compile with a map-file.\n"));
	if (argc > 2)
		warning("Detecting multiple arguments.\nOnly the first argument will be used.\nPlease ensure the first argument is a map-file.\n");
	if (check_extension(map_file, ".ber") <= 0)
		return (error_msg("Please ensure the map-file you compile with is a .ber extension"));
	return (1);
}

void	free_map(char **map_data, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->row)
	{
		free(map_data[i++]);
		free(map->map_reset);
	}
	free(map_data);
	free(map->map_reset);
}

int	backup_map(t_map *map, char **map_data)
{
	int	i;
	int	row;

	row = map->row;
	map->map_reset = malloc(sizeof(char *) * row + 1);
	if (!map->map_reset)
		return (error_msg("Caution: Map Backup Failed."));
	i = -1;
	while (++i < row)
		map->map_reset[i] = ft_strdup(map_data[i]);
	map->map_reset[i] = NULL;
	map->item_reset = map->valid.consumable_count;
	return (1);
}

int	recover(t_map *map)
{
	int	i;
	int	row;

	i = 0;
	while (i <= map->row)
		free(map->map[i++]);
	free(map->map);
	row = map->row;
	map->map = malloc(sizeof(char *) * row + 1);
	if (!map->map)
		return (0);
	i = -1;
	while (++i < row)
		map->map[i] = ft_strdup(map->map_reset[i]);
	map->map[i] = NULL;
	map->valid.consumable_count = map->item_reset;
	return (1);
}