#include "so_long.h"

char	*player_direction(t_game *game)
{
	char	position;

	position = game->direction;
	if (position == 'L')
		return ("./textures/player/left.xpm");
	else if (position == 'U')
		return ("./textures/player/up.xpm");
	else if (position == 'D')
		return ("./textures/player/down.xpm");
	else
		return ("./textures/player/right.xpm");
}

void	set_sprite(t_game *game, char ch, int row, int col)
{
	void	*sprite;
	char	*path;
	int		sprite_width;
	int		sprite_height;

	path = NULL;
	if (ch == '0')
		path = "./textures/floor.xpm";
	else if (ch == '1')
		path = "./textures/wall.xpm";
	else if (ch == 'C')
		path = "./textures/collectible.xpm";
	else if (ch == 'E')
		path = "./textures/exit.xpm";
	else if (ch == 'P')
		path = player_direction(game);
	sprite = mlx_xpm_file_to_image(game->mlx, path, \
		&sprite_width, &sprite_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		sprite, col * PIXEL, row * PIXEL);
	mlx_destroy_image(game->mlx, sprite);
}

int	move_player(t_game *game, int row, int col)
{
	game->grid[row][col] = '0';
	set_sprite(game, game->grid[row][col], row, col);
	if (game->direction == 'L')
		col--;
	else if (game->direction == 'R')
		col++;
	else if (game->direction == 'D')
		row++;
	else if (game->direction == 'U')
		row--;
	game->grid[row][col] = 'P';
	set_sprite(game, game->grid[row][col], row, col);
	game->move_count++;
	ft_printf("%d\n", game->move_count);
	return (1);
}

void	init_game(t_game *game)
{
	int		row;
	int		col;
	char	ch;

	game->direction = 'R';
	row = 0;
	while (game->grid[row])
	{
		col = 0;
		while (game->grid[row][col])
		{
			ch = game->grid[row][col];
			set_sprite(game, ch, row, col);
			col++;
		}
		row++;
	}
}

int	game_fits_screen(t_game *game)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (game->col * PIXEL > screen_width || game->row * PIXEL > screen_height)
	{
		ft_printf("Map doesn't fit the screen.\n");
		return (0);
	}
	return (1);
}
