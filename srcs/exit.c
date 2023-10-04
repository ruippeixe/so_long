#include "so_long.h"

void	path_error(t_game *game)
{
	int	y;

	y = 0;
	while (game->grid[y])
	{
		free(game->grid[y]);
		y++;
	}
	free(game->grid);
	ft_printf("Error: Invalid path.\n");
	exit(1);
}

void	free_grid(t_game *game, int idx_row)
{
	int	row;

	row = 0;
	if (game->grid)
	{
		if (game->grid[row])
		{
			while (row <= idx_row)
			{
				free(game->grid[row]);
				row++;
			}
		}
		free(game->grid);
	}
}

int	parsing_error_handle(char *line, t_game *game, int idx)
{
	free_grid(game, idx);
	free(line);
	return (0);
}

int	cleanup_and_exit_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	if (game)
	{
		free_grid(game, game->row);
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit(0);
}

int	quit_game(t_game *game)
{
	if (check_cep(game, 'C') > 0)
		return (0);
	cleanup_and_exit_game(game);
	return (1);
}
