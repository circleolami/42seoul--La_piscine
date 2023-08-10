CFLAGS= -Wall -Wextra -Werror
CC = gcc
AR = ar rcs
NAME = libft.a
DIR_S = ./srcs
DIR_I = ./includes
SOURCES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(DIR_S)/%.o:$(DIR_S)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_I)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
