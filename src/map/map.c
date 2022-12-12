#include "../../so_long.h"

char	**init_map(t_root *root, int argc, char **argv)
{
	char	**map;

	if (!valid_map(argc, argv[1]))
		return (nullptr_error("Invalid map during initilization."));
	map = read_map(argv[1], &root->game->map);
	if (!map)
		return (nullptr_error("Error creating map!"));
	return (map);
}

int	counter(int fd, int row_count, int column_count, t_map *map)
{
	int		size;
	char	buffer;

	while (true)
	{
		size = read(fd, &buffer, 1);
		if (size < 0)
			return (error_msg("Unable to read file."));
		verify(check(buffer, map, column_count, row_count), map);
		if (buffer == '\n')
			row_count++;
		else if (buffer != '\n' && size > 0)
			column_count++;
		if (map->column_size == 0 && buffer == '\n')
			map->column_size = column_count - 1;
		if (map->column_size != column_count - 1 && (buffer == '\n' || size == 0))
			return (error_msg("Map is not even. Please use a flat, four sided map."));
		else if (buffer == '\n')
			column_count = 0;
		if (size == 0)
			break ;
	}
	map->column = map->column_size + 1;
	return (row_count);
}

int	rows(char *map_data, t_map *map)
{
	int	fd;
	int	row_count;
	int	column_count;

	fd = open(map_data, O_RDONLY);
	if (fd < 0)
		return (error_msg("Error opening file."));
	row_count = 1;
	column_count = 0;
	row_count = counter(fd, row_count, column_count, map);
	if (row_count <= 0)
		return (error_msg("Error with number of rows in the map."));
	close(fd);
	return (row_count);
}

static char	**allocate_map(char *path, t_map *map)
{
	char	**map_output;

	map->row = rows(path, map);
	if (map->valid <= 0)
		return (nullptr_error("Invalid Map during allocation."));
	if (map->row <= 0)
		return (nullptr_error("Error in map, possibly empty."));
	map_output = malloc(sizeof(char *) * map->row + 1);
	if (!map_output)
		return (nullptr_error("Memory Error when allocating for Map."));
	return (map_output);
}

char	**read_map(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	**map_output;

	i = 0;
	map_output = allocate_map(path, map);
	if (!map_output)
		return (nullptr_error("Error allocating for map."));
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &map_output[i++]))
		;
	map_output[i] = NULL;
	check_last_line(map_output[i - 1], map);
	backup_map(map, map_output);
	if (map->valid == 0)
	{
		free_map(map_output, map);
		return (nullptr_error("Map Not Valid."));
	}
	close(fd);
	return (map_output);
}