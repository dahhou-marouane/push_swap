NAME_MAN = push_swap
NAME_BONUS = checker

CFLAGS = -g -Wall -Wextra -Werror

FILE_BONUS = ft_atoi_bonus.c ft_rotate_bonus.c ft_stack_utils_bonus.c ft_swap_bonus.c  \
		ft_do_moves_bonus.c ft_r_rotate_bonus.c ft_strjoin_bonus.c get_next_line_bonus.c \
		ft_error_bonus.c ft_split_bonus.c ft_strlen_bonus.c parcing_bonus.c \
		ft_push_bonus.c ft_success_bonus.c get_next_line_utils_bonus.c main_bonus.c ft_stack_utils2_bonus.c 


FILES_MAN = ft_error.c main.c parcing.c ft_strlen.c ft_strjoin.c \
			ft_split.c ft_atoi.c ft_stack_utils.c ft_swap.c ft_rotate.c \
			ft_r_rotate.c ft_push.c ft_hard_sort.c ft_algo.c ft_hard_sort2.c\
			ft_change_num_to_idx.c ft_move_b_to_a.c ft_move_a_to_b.c ft_algo_helpers.c\
			

OBJ_MAN = $(FILES_MAN:.c=.o)
OBJ_BONUS = $(FILE_BONUS:.c=.o)

all : $(NAME_MAN)

bonus: $(NAME_BONUS)

$(NAME_MAN) : $(OBJ_MAN)
	cc $(CFLAGS) $(OBJ_MAN) -o $(NAME_MAN)


$(NAME_BONUS) : $(OBJ_BONUS)
	cc $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c push_swap_bonus.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_MAN) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME_MAN) $(NAME_BONUS)


re: fclean all

.PHONY: clean 