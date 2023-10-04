#include "so_long.h"

int	error_message(void)
{
	ft_printf("Error: Unable to run the program.\n");
	return (0);
}

int	initialize_and_run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game_fits_screen(game))
	{
		error_message();
		cleanup_and_exit_game(game);
	}
	game->mlx_win = mlx_new_window(game->mlx,
			game->col * PIXEL, game->row * PIXEL, "so_long");
	game->move_count = 0;
	init_game(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &handle_keyboard_input, game);
	mlx_hook(game->mlx_win, 33, 1L << 2, &cleanup_and_exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (!(argc == 2))
		return (error_message());
	game.map = argv[1];
	if (parse_map(&game))
		initialize_and_run_game(&game);
	else
		return (error_message());
	return (0);
}
