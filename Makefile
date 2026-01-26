# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 02:53:28 by mdahhou           #+#    #+#              #
#    Updated: 2026/01/26 22:33:14 by mdahhou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -g -Wall -Wextra -Werror
FILES = ft_error.c main.c parcing.c ft_strlen.c ft_strjoin.c

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