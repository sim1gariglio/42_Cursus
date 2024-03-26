# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by sgarigli          #+#    #+#              #
#    Updated: 2024/02/07 11:19:26 by sgarigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

NAME = philo

SRCS = srcs/input.c \
	srcs/list_utils.c \
	srcs/philo_utils.c \
	srcs/thread_utils.c \
	srcs/philo.c \
	srcs/error.c \
	srcs/actions.c \
	srcs/time_utils.c

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -lpthread -o $(NAME)
	@echo "Let's start !!"

clean:
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

fclean: clean
	@make fclean -C .././philo_bonus

re: fclean all 

bonus:
	@make all -C .././philo_bonus

.PHONY: all clean fclean re bonus
