CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext -lm

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = fractol
BONUS_NAME = fractol_bonus

SRCS = fractol.c utils.c fractals.c keypress.c keypress2.c mouse.c menu.c colors.c

BONUS_SRCS = fractol.c utils.c fractals.c keypress.c keypress2.c mouse.c menu.c colors.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) $(MLX) $(LIBFT) -o $(NAME)

bonus:
	@make all -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(BONUS_SRCS) $(MLX) $(LIBFT) -o $(BONUS_NAME)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

recompile: 
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) $(MLX) $(LIBFT) -o $(NAME)
	@make clean

.PHONY: all clean fclean re bonus recompile
