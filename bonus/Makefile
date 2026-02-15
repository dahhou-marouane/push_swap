NAME = checker
CFLAGS = -g -Wall -Wextra -Werror
FILES = ft_atoi_bonus.c ft_rotate_bonus.c ft_stack_utils_bonus.c ft_swap_bonus.c  \
		ft_do_moves_bonus.c ft_r_rotate_bonus.c ft_strjoin_bonus.c get_next_line_bonus.c \
		ft_error_bonus.c ft_split_bonus.c ft_strlen_bonus.c parcing_bonus.c \
		ft_push_bonus.c ft_success_bonus.c get_next_line_utils_bonus.c main_bonus.c ft_stack_utils2_bonus.c 
OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap_bonus.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: clean 
