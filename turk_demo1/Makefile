NAME = libturk_demo.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g

SRCS = turk_demo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
