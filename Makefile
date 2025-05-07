# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 18:46:57 by fileonar          #+#    #+#              #
#    Updated: 2025/05/07 22:00:42 by fileonar         ###   ########.fr        #
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
		# philosphers.c \
		
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
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re

# ifeq ($(DEBUG),1)
# CFLAGS+=-g3
# clean_when_debug: fclean
# endif