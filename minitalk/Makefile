# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by sgarigli          #+#    #+#              #
#    Updated: 2024/02/07 16:45:18 by sgarigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = server
CLIENT = client

SRCS_C = client.c
SRCS_S = server.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) -o $(CLIENT)
	@echo "Let's start !!"

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f $(CLIENT)

re: fclean all

bonus:
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) -o $(CLIENT)

ciao:
	@echo "scemo chi legge"

rebu:
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) -o $(CLIENT)
	@echo "Done !!"
	
parrot:
	@curl parrot.live
	kill

.PHONY: all clean fclean re rebu ciao bonus
