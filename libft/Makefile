# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pallspic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:50:17 by pallspic          #+#    #+#              #
#    Updated: 2019/08/31 15:15:53 by pallspic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean del check

.SECONDARY: $(OBJ)

override ARFLAGS = rc

override CFLAGS = -Wall -Werror -Wextra -I.

override CC = gcc

NAME = libft.a

SRC = ft_base_funcs/ft_atoi.c \
	  ft_base_funcs/ft_isalnum.c \
	  ft_base_funcs/ft_isalpha.c \
	  ft_base_funcs/ft_isascii.c \
	  ft_base_funcs/ft_isdigit.c \
	  ft_base_funcs/ft_isprint.c \
	  ft_base_funcs/ft_isspace.c \
	  ft_base_funcs/ft_itoa.c \
	  ft_base_funcs/ft_bzero.c \
	  ft_base_funcs/ft_memalloc.c \
	  ft_base_funcs/ft_lstiter.c \
	  ft_base_funcs/ft_memcpy.c \
	  ft_base_funcs/ft_memcmp.c \
	  ft_base_funcs/ft_memset.c \
	  ft_base_funcs/ft_memchr.c \
	  ft_base_funcs/ft_memmove.c \
	  ft_base_funcs/ft_memdel.c \
	  ft_base_funcs/ft_memccpy.c \
	  ft_base_funcs/ft_putnbr.c \
	  ft_base_funcs/ft_putchar.c \
	  ft_base_funcs/ft_putstr.c \
	  ft_base_funcs/ft_putendl.c \
	  ft_base_funcs/ft_putnbr_fd.c \
	  ft_base_funcs/ft_putchar_fd.c \
	  ft_base_funcs/ft_putstr_fd.c \
	  ft_base_funcs/ft_putendl_fd.c \
	  ft_base_funcs/ft_lstmap.c \
	  ft_base_funcs/ft_strcat.c \
	  ft_base_funcs/ft_strncat.c \
	  ft_base_funcs/ft_strlcat.c \
	  ft_base_funcs/ft_strchr.c \
	  ft_base_funcs/ft_strrchr.c \
	  ft_base_funcs/ft_strclr.c \
	  ft_base_funcs/ft_strcmp.c \
	  ft_base_funcs/ft_strncmp.c \
	  ft_base_funcs/ft_strcpy.c \
	  ft_base_funcs/ft_strncpy.c \
	  ft_base_funcs/ft_strsplit.c \
	  ft_base_funcs/ft_strdel.c \
	  ft_base_funcs/ft_strdup.c \
	  ft_base_funcs/ft_strequ.c \
	  ft_base_funcs/ft_strnequ.c \
	  ft_base_funcs/ft_striter.c \
	  ft_base_funcs/ft_striteri.c \
	  ft_base_funcs/ft_strjoin.c \
	  ft_base_funcs/ft_strlen.c \
	  ft_base_funcs/ft_strmap.c \
	  ft_base_funcs/ft_strmapi.c \
	  ft_base_funcs/ft_strnew.c \
	  ft_base_funcs/ft_strstr.c \
	  ft_base_funcs/ft_strnstr.c \
	  ft_base_funcs/ft_strsub.c \
	  ft_base_funcs/ft_strtrim.c \
	  ft_base_funcs/ft_toupper.c \
	  ft_base_funcs/ft_tolower.c \
	  ft_base_funcs/ft_lstnew.c \
	  ft_base_funcs/ft_lstdelone.c \
	  ft_base_funcs/ft_lstdel.c \
	  ft_base_funcs/ft_lstadd.c \
	  ft_extra_funcs/ft_strrev.c \
	  ft_extra_funcs/ft_strfchr.c \
	  ft_extra_funcs/ft_strerase.c \
	  ft_extra_funcs/ft_abs.c \
	  ft_extra_funcs/ft_itoa_base.c \
	  ft_extra_funcs/ft_pow.c \
	  ft_extra_funcs/ft_nmult.c \
	  ft_extra_funcs/ft_nsize.c \
	  ft_extra_funcs/ft_strjoinfree.c \
	  ft_extra_funcs/ft_isupper.c \
	  ft_extra_funcs/ft_islower.c \
	  ft_extra_funcs/ft_get.c \
	  ft_extra_funcs/ft_max.c \
	  ft_extra_funcs/ft_memsetloc.c \
	  ft_long_math/ft_long.c \
	  ft_long_math/ft_long_div.c \
	  ft_long_math/ft_long_diff.c \
	  ft_long_math/ft_long_sum.c \
	  ft_long_math/ft_long_utils.c \
	  ft_long_math/ft_make_nline.c \
	  ft_long_math/ft_long_mult.c \
	  ft_printf/ft_printf.c \
	  ft_printf/parsers.c \
	  ft_printf/utilities.c \
	  get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -o $@

all: $(NAME)

$(NAME): $(NAME)($(OBJ))
	ranlib $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean del

del:
	/bin/rm -f $(NAME)

re: fclean all

check: del all clean
