#include "so_long.h"

int	map_height(char *map)
{
	int		i;
	int		fd;
	char	*row;

	fd = open(map, O_RDONLY);
	row = get_next_line(fd);
	i = 0;
	while (row)
	{
		i++;
		free(row);
		row = get_next_line(fd);
	}
	return (i);
}

int	is_ch_valid(char ch)
{
	char	*valid_ch;
	int		i;

	i = 0;
	valid_ch = "01CEP";
	while (valid_ch[i])
	{
		if (ch == valid_ch[i])
			return (1);
		i++;
	}
	return (0);
}

int	populate_row(char *line, char **grid, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (!is_ch_valid(line[i]))
			return (0);
		grid[0][i] = line[i];
		i++;
	}
	grid[0][i] = '\0';
	return (1);
}

int	populate_map(t_game *game)
{
	char	*line;
	int		cols;
	int		row;
	int		fd;

	row = 0;
	game->grid = malloc(sizeof(char *) * (map_height(game->map) + 1));
	if (!game->grid)
		return (0);
	fd = open(game->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		cols = 0;
		while (line[cols] && line[cols] != '\n')
			cols++;
		game->grid[row] = malloc(sizeof(char) * (cols + 1));
		if (!game->grid[row] || !populate_row(line, &game->grid[row], cols))
			return (parsing_error_handle(line, game, row));
		free(line);
		line = get_next_line(fd);
		row++;
	}
	game->grid[row] = NULL;
	return (1);
}
