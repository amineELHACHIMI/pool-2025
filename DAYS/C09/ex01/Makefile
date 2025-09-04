# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelhach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 22:44:20 by amelhach          #+#    #+#              #
#    Updated: 2025/09/03 22:46:04 by amelhach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_swap.c srcs/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

