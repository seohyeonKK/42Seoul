# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 00:31:19 by seohyuki          #+#    #+#              #
#    Updated: 2022/09/29 02:50:58 by seohyuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror

CLIENT = client
SERVER = server
HEADER = ft_printf.h minitalk.h

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
OTHER_SRCS = ft_atoi.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_pointer.c  ft_print_string.c  ft_print_unsigned.c ft_printf.c

CLIENT_OBJS=$(CLIENT_SRCS:.c=.o)
SERVER_OBJS=$(SERVER_SRCS:.c=.o)
OTHER_OBJS=$(OTHER_SRCS:.c=.o)

CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_OBJS=$(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS=$(SERVER_SRCS:.c=.o)
NAME=Minitalk

BONUS=0

ifeq ($(BONUS), 1)
	S_OBJECTS = $(SERVER_BONUS_OBJS) $(OTHER_OBJS)
	S_SRCS = $(SERVER_BONUS_SRCS) $(OTHER_SRCS)
	C_OBJECTS = $(CLIENT_BONUS_OBJS) $(OTHER_OBJS)
	C_SRCS =  $(CLIENT_BONUS_SRCS) $(OTHER_SRCS)
else
	S_OBJECTS = $(SERVER_OBJS) $(OTHER_OBJS)
	S_SRCS = $(SERVER_SRCS) $(OTHER_SRCS)
	C_OBJECTS = $(CLIENT_OBJS) $(OTHER_OBJS)
	C_SRCS =  $(CLIENT_SRCS) $(OTHER_SRCS)
endif

all: client server

.c.o: $(HEADER) $(S_SRCS) $(C_SRCS)
	$(CC) $(CFLAGS) -c $(S_SRCS) $(C_SRCS)

client: $(C_OBJECTS) $(OTHER_OBJS)
	$(CC) $(C_OBJECTS) -o $(CLIENT)

server: $(S_OBJECTS) $(OTHER_OBJS)
	$(CC) $(S_OBJECTS) -o $(SERVER)

clean:
	rm -f $(S_OBJECTS) $(C_OBJECTS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

bonus:
	make BONUS=1

.PHONY: all clean fclean re bonus
