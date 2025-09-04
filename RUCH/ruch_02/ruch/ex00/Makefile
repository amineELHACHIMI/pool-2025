NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCS = src/main.c src/utils.c src/utils2.c src/dict.c src/convert.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

