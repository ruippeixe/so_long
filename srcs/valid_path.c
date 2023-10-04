#include "so_long.h"

void	free_temp(char **temp)
{
	int	row;

	row = 0;
	while (temp[row])
	{
		free(temp[row]);
		row++;
	}
	free(temp);
}

int	check_remaining_collectibles(char **temp)
{
	int	row;
	int	col;

	row = 0;
	while (temp[row])
	{
		col = 0;
		while (temp[row][col])
		{
			if (temp[row][col] == 'C')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	check_player_position(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->grid[row])
	{
		col = 0;
		while (game->grid[row][col])
		{
			if (game->grid[row][col] == 'P')
			{
				game->p_row_pos = row;
				game->p_col_pos = col;
			}
			col++;
		}
		row++;
	}
}

void	flood_fill(t_game *game, int row, int col, char **temp)
{
	if (temp[row][col] == '1' || temp[row][col] == 'P')
		return ;
	else if (temp[row][col] == '0')
		temp[row][col] = 'P';
	else if (temp[row][col] == 'C')
		temp[row][col] = 'P';
	else if (temp[row][col] == 'E')
	{
		game->check_exit++;
		temp[row][col] = 'P';
	}
	flood_fill(game, row + 1, col, temp);
	flood_fill(game, row - 1, col, temp);
	flood_fill(game, row, col + 1, temp);
	flood_fill(game, row, col - 1, temp);
}

int	valid_path_checker(t_game *game)
{
	char	**temp;
	int		row;

	row = -1;
	game->check_exit = 0;
	temp = malloc(sizeof(char *) * (game->row + 1));
	if (!temp)
		return (0);
	while (game->grid[++row])
		temp[row] = ft_strdup(game->grid[row]);
	temp[row] = 0;
	check_player_position(game);
	flood_fill(game, game->p_row_pos + 1, game->p_col_pos, temp);
	flood_fill(game, game->p_row_pos - 1, game->p_col_pos, temp);
	flood_fill(game, game->p_row_pos, game->p_col_pos + 1, temp);
	flood_fill(game, game->p_row_pos, game->p_col_pos - 1, temp);
	if (game->check_exit == 0 || !check_remaining_collectibles(temp))
	{
		free_temp(temp);
		return (0);
	}
	free_temp(temp);
	return (1);
}
