# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: one <one@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 02:53:28 by mdahhou           #+#    #+#              #
#    Updated: 2026/01/27 01:14:54 by one              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -g -Wall -Wextra -Werror
FILES = ft_error.c main.c parcing.c ft_strlen.c ft_strjoin.c ft_split.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o push_swap

%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean 