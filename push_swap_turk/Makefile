# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 13:28:07 by ngungor           #+#    #+#              #
#    Updated: 2025/08/19 13:28:12 by ngungor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
		initalisation_of_stack.c \
		push_swap_operations.c \
		push_swap_operations_2.c \
		sort_less_than_5.c \
		normalizing.c \
		radix_sort.c \
		helper.c \
		ft_split.c \
		push_swap_2.c \
		push_swap_3.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
