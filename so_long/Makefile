# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 16:37:04 by seohyuki          #+#    #+#              #
#    Updated: 2022/10/30 03:27:27 by seohyuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
SRC=main.c
OBJ=$(SRC:.c=.o)
NAME=so_long
LIBFT=Libft
MLX=mlx
GNL=gnl

%.o: %.c
	arch -x86_64 $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	arch -x86_64 make -C $(LIBFT)
	arch -x86_64 make -C $(GNL)
	arch -x86_64 make -C $(MLX)
	arch -x86_64 $(CC) $(LIBFT)/libft.a $(MLX)/libmlx.a $(GNL)/gnl.a $(OBJ) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: $(NAME)
clean:
	make clean -C $(MLX)
	make clean -C $(LIBFT)
	make clean -C $(GNL)
	rm -f $(OBJ)
fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(GNL)/gnl.a
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
