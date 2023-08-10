CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = rush-02
SRC = dic_free.c main.c print_all.c print_under_thousand.c parse.c others00.c others01.c
OBJ = dic_free.o main.o print_all.o print_under_thousand.o parse.o others00.o others01.o
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC) others01.h others00.h all_others.h
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
