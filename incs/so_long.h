#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define PIXEL 50
# define LEFT_KEY 97
# define RIGHT_KEY 100
# define DOWN_KEY 115
# define UP_KEY 119

typedef struct s_game {
	char	*map;
	char	**grid;
	int		row;
	int		col;
	int		p_row_pos;
	int		p_col_pos;
	int		check_exit;
	void	*mlx;
	void	*mlx_win;
	int		move_count;
	char	direction;

}	t_game;

int		parse_map(t_game *game);
int		populate_map(t_game *game);
int		map_height(char *map);
int		parsing_error_handle(char *line, t_game *game, int row);
void	free_grid(t_game *game, int row);
int		valid_path_checker(t_game *game);
void	init_game(t_game *game);
int		game_fits_screen(t_game *game);
int		cleanup_and_exit_game(t_game *game);
int		handle_keyboard_input(int keycode, t_game *game);
int		quit_game(t_game *game);
int		check_cep(t_game *game, char ch);
int		move_player(t_game *game, int row, int col);
void	path_error(t_game *vars);

#endif
