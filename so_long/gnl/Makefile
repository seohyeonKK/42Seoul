# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:23:14 by seohyuki          #+#    #+#              #
#    Updated: 2022/10/28 16:40:36 by seohyuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

HEADER=get_next_line.h

SRCS=get_next_line.c get_next_line_utils.c
OBJS=$(SRCS:.c=.o)

NAME=gnl.a

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)

all : $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

bonus:
	make BONUS=1

.PHONY: all clean fclean re bonus
