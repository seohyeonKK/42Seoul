# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 16:37:04 by seohyuki          #+#    #+#              #
#    Updated: 2022/10/30 06:39:24 by seohyuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
SRC=main.c check.c draw.c exit.c key_event.c map.c
OBJ=$(SRC:.c=.o)

SRC_BONUS=main_bonus.c check_bonus.c draw_bonus.c exit_bonus.c key_event_bonus.c map_bonus.c
OBJ_BONUS=$(SRC_BONUS:.c=.o)
NAME=so_long
LIBFT=Libft
MLX=mlx
GNL=gnl

BONUS=0

ifeq ($(BONUS), 1)
	OBJECTS = $(OBJ_BONUS)
else
	OBJECTS = $(OBJ)
endif

%.o: %.c
	arch -x86_64 $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJECTS)
	arch -x86_64 make -C $(LIBFT)
	arch -x86_64 make -C $(GNL)
	arch -x86_64 make -C $(MLX)
	arch -x86_64 $(CC) $(LIBFT)/libft.a $(MLX)/libmlx.a $(GNL)/gnl.a $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)
clean:
	make clean -C $(MLX)
	make clean -C $(LIBFT)
	make clean -C $(GNL)
	rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(GNL)/gnl.a
	rm -f $(NAME)
re: fclean all
bonus:
	make BONUS=1

.PHONY: all clean fclean re bonus
