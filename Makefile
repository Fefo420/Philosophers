# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 18:46:57 by fileonar          #+#    #+#              #
#    Updated: 2025/05/09 00:29:47 by fefo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -fsanitize=address

CC = gcc
CFLAGS =  -Wall -Werror -Wextra -g 

NAME = philosophers

SRC =	main.c \
		init.c \
		checkers.c \
		mutex.c \
		utils.c \
		utils2.c \
		more_utils.c \
		philosophers.c \
		actions.c \
		
HEADER = philosophers.h

OBJS = $(SRC:%.c=bin/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bin/%.o : %.c | bin
	$(CC) -c -o $@ $< $(CFLAGS)

bin:
	@mkdir -p bin

clean:
	@rm -fr bin

fclean: clean
	@rm -f $(NAME)


re: clean fclean all

.PHONY: all clean fclean re

# ifeq ($(DEBUG),1)
# CFLAGS+=-g3
# clean_when_debug: fclean
# endif