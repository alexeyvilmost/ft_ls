# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2020/02/24 18:13:35 by pallspic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean libft a_out ls_out test

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Iincludes -o $@

LIB_MAKE = $(MAKE) -C $(LIB_DIR)

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

NAME = ft_ls

SRC = main.c ls_sort.c print.c comparators.c

OBJ = $(SRC:.c=.o)

TEST_FLAGS = -lRtra

TEST_DIR = ~/

all: libft $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -Llibft -lft $(OBJ)

libft:
	$(LIB_MAKE)

a_out:
	./$(NAME) $(TEST_FLAGS) $(TEST_DIR) > $@

ls_out:
	ls $(TEST_FLAGS) $(TEST_DIR) > $@

test: all a_out ls_out
	diff a_out ls_out

%.a:
	$(LIB_MAKE)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

fclean: clean
	$(RM) $(NAME)
	$(LIB_MAKE) fclean

clean:
	$(RM) $(OBJ)
	$(LIB_MAKE) clean

re: fclean all