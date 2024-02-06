# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 12:09:22 by sgarigli          #+#    #+#              #
#    Updated: 2024/01/12 10:56:04 by sgarigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
	ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
	ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

GNL_DIR = get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line_bonus.c $(GNL_DIR)/get_next_line_utils_bonus.c \

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRC = $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_printf_hex.c \
				$(FT_PRINTF_DIR)/ft_printf_pointer.c $(FT_PRINTF_DIR)/ft_printf_utils.c \
				$(FT_PRINTF_DIR)/ft_uitoa.c

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o) $(FT_PRINTF_SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Created files.o"
	@echo "Created libft.a"

%.o: %.c libft.h $(GNL_DIR)/get_next_line_bonus.h $(FT_PRINTF_DIR)/ft_printf.h
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Removed files.o"
	
fclean: clean
	@rm -f $(NAME)
	@echo "Removed libft.a"

re: fclean all

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

.PHONY: NAME all clean fclean re bonus
