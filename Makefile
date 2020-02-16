# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2019/07/21 12:52:13 by pallspic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Iincludes -o $@

LIB_MAKE = $(MAKE) -C $(LIB_DIR)

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

NAME = ft_ls

SRC = main.c ls_sort.c print.c comparators.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -Llibft -lft $(OBJ)

libft:
	$(LIB_MAKE)

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