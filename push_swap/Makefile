# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by sgarigli          #+#    #+#              #
#    Updated: 2024/01/10 16:27:03 by sgarigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
BONUS_NAME = checker

SRCS = srcs/push_swap.c \
	srcs/push_swap_utils.c \
	srcs/input.c \
	srcs/input_utils.c \
	srcs/list_utils.c \
	srcs/moves_0.c \
	srcs/moves_1.c \
	srcs/sort_basic.c \
	srcs/algorithm.c \
	srcs/algorithm_utils.c

BONUS_SRCS = srcs/push_swap_utils.c \
	srcs/input.c \
	srcs/input_utils.c \
	srcs/list_utils.c \
	srcs/moves_0.c \
	srcs/moves_1.c \
	srcs/checker_moves_0.c \
	srcs/checker_moves_1.c \
	srcs/checker.c \
	srcs/checker_utils.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "Let's start !!"

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all bonus

ciao:
	@echo "scemo chi legge"

rebu:
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS_NAME)
	@echo "Done !!"

bonus:
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS_NAME)
	@echo "Here you go!"

.PHONY: all clean fclean re rebu bonus ciao
