#include "so_long.h"

int	go_left(t_game *game)
{
	int	y;
	int	x;

	game->direction = 'L';
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				if (game->grid[y][x - 1] == '0' || game->grid[y][x - 1] == 'C')
					return (move_player(game, y, x));
				else if (game->grid[y][x - 1] == 'E' && !check_cep(game, 'C'))
				{
					move_player(game, y, x);
					return (quit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	go_right(t_game *game)
{
	int	y;
	int	x;

	game->direction = 'R';
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				if (game->grid[y][x + 1] == '0' || game->grid[y][x + 1] == 'C')
					return (move_player(game, y, x));
				else if (game->grid[y][x + 1] == 'E' && !check_cep(game, 'C'))
				{
					move_player(game, y, x);
					return (quit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	go_down(t_game *game)
{
	int	y;
	int	x;

	game->direction = 'D';
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				if (game->grid[y + 1][x] == '0' || game->grid[y + 1][x] == 'C')
					return (move_player(game, y, x));
				else if (game->grid[y + 1][x] == 'E' && !check_cep(game, 'C'))
				{
					move_player(game, y, x);
					return (quit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	go_up(t_game *game)
{
	int	y;
	int	x;

	game->direction = 'U';
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				if (game->grid[y - 1][x] == '0' || game->grid[y - 1][x] == 'C')
					return (move_player(game, y, x));
				else if (game->grid[y - 1][x] == 'E' && !check_cep(game, 'C'))
				{
					move_player(game, y, x);
					return (quit_game(game));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	handle_keyboard_input(int keycode, t_game *game)
{
	if (keycode == LEFT_KEY)
		return (go_left(game));
	else if (keycode == RIGHT_KEY)
		return (go_right(game));
	else if (keycode == DOWN_KEY)
		return (go_down(game));
	else if (keycode == UP_KEY)
		return (go_up(game));
	else if (keycode == 65307)
		return (cleanup_and_exit_game(game));
	return (0);
}
