#include "so_long.h"

int	check_cep(t_game *game, char ch)
{
	int	row;
	int	cols;
	int	i;

	row = 0;
	i = 0;
	while (game->grid[row])
	{
		cols = 0;
		while (game->grid[row][cols])
		{
			if (game->grid[row][cols] == ch)
				i++;
			cols++;
		}
		row++;
	}
	return (i);
}

int	check_walls(t_game *game)
{
	int	row;
	int	cols;

	row = 0;
	while (game->grid[row])
	{
		cols = 0;
		while (game->grid[row][cols])
		{
			if (game->grid[row][cols] != '1')
			{
				if (row == 0 || cols == 0 \
				|| row == game->row - 1 \
				|| cols == game->col - 1)
				{
					free_grid(game, game->row);
					ft_printf("The map is not enclosed by walls.\n");
					return (0);
				}
			}
			cols++;
		}
		row++;
	}
	return (1);
}

int	is_rectangular(t_game *game)
{
	int	row;
	int	cols;
	int	last_row;

	row = 0;
	while (game->grid[row])
	{
		cols = 0;
		while (game->grid[row][cols])
			cols++;
		if (row == 0)
			last_row = cols;
		if (row != 0 && last_row != cols)
		{
			free_grid(game, map_height(game->map));
			ft_printf("The map is not rectangular.\n");
			return (0);
		}
		row++;
	}
	game->row = row;
	game->col = cols;
	return (1);
}

int	check_file_extension(t_game *game)
{
	char	*valid_extension;
	size_t	map_filename_length;
	char	*map_extension_start;

	valid_extension = ".ber";
	map_filename_length = ft_strlen(game->map);
	map_extension_start = game->map + map_filename_length - 4;
	if (ft_strnstr(game->map, valid_extension, map_filename_length)
		!= map_extension_start)
	{
		ft_printf("Wrong file extension.\n");
		return (0);
	}
	return (1);
}

int	parse_map(t_game *game)
{
	if (!check_file_extension(game))
		return (0);
	if (!populate_map(game) || !is_rectangular(game) || !check_walls(game))
		return (0);
	if (!check_cep(game, 'C') \
		|| check_cep(game, 'E') != 1 \
		|| check_cep(game, 'P') != 1)
	{
		free_grid(game, game->row);
		ft_printf("Check the player, collectibles an exit.\n");
		return (0);
	}
	if (!valid_path_checker(game))
	{
		path_error(game);
		return (0);
	}
	return (1);
}
