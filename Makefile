NAME = push_swap
CFLAGS = -g -Wall -Wextra -Werror
FILES = ft_error.c main.c parcing.c ft_strlen.c ft_strjoin.c \
			ft_split.c ft_atoi.c ft_stack_utils.c ft_swap.c ft_rotate.c \
			ft_r_rotate.c ft_push.c sort_utils.c chunk_sort.c
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