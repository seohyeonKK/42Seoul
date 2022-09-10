# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 21:38:00 by seohyuki          #+#    #+#              #
#    Updated: 2022/09/10 22:33:28 by seohyuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

HEADER=ft_printf.h

SRCS=ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_pointer.c ft_print_string.c ft_print_unsigned.c
OBJS=$(SRCS:.c=.o)

NAME=libftprintf.a

OBJECTS = $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)
all : $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
