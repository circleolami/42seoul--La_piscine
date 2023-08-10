CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = do-op
SRCS = ft_putnbr.c ft_atoi.c operator.c do-op.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

/%.o : /%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
