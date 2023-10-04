NAME = so_long
CC =	cc
CFLAGS = -Wall -Wextra -Werror $(INCS)
# CFLAGS += -fsanitize=address -g3

SRC = main.c parsing.c map_setup.c exit.c valid_path.c init.c movements.c
OBJ = $(addprefix srcs/, $(SRC:.c=.o))

INCS = -I incs -I libs/ft_printf -I libs/libft -I libs/get_next_line -I libs/minilibx-linux
LIB = -L libs/ -lft -L libs/minilibx-linux -lmlx -lX11 -lXext -lm -lbsd -lz

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C libs
	@make --no-print-directory -C libs/minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

clean:
	@make --no-print-directory -C libs clean
	@make -s -C libs/minilibx-linux clean
	@rm -rf $(OBJ)
	@echo "object files removed."

fclean:		clean
	@make --no-print-directory -C libs fclean
	@rm -rf $(NAME)
	@echo "binary file removed."

re: fclean all

.PHONY: all clean fclean re