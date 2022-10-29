/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:43:59 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 06:17:37 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# define SIZE 25
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define X_EVENT_KEY_EXIT 17

typedef struct s_game{
	int		size;
	void	*mlx;
	void	*wnd;
	void	*w;
	void	*a;
	void	*s;
	void	*d;
	void	*b;
	void	*f;
	void	*e;
	void	*c;
	int		wnd_w;
	int		wnd_h;
	char	**map;
	int		p_i;
	int		p_j;
	int		p_c;
	int		move;
	int		p_cnt;
	int		e_cnt;
	int		c_cnt;
	int		row;
	int		col;
}t_game;

void	game_init(t_game	*g);
char	**get_map(char	*filename);
char	*read_map(int map_file);
char	**make_map(int map_file);
void	error(void);
void	map_check(t_game	*g);
void	free_error(char **map);
int		wall_check(char *str, int is_fr, int length);
void	object_check(t_game *g);
void	cnt_object(t_game *g);
void	check_object_type(char ch, t_game *g, int i, int j);
void	draw_map(t_game g);
void	put_img(t_game g, int x, int y, char ch);
void	go(t_game *g, int i, int j, void *img);
void	exit_game(int win, t_game *g);
void	destroy(t_game *g);
int		key_hook(int key, t_game *g);
int		x_exit(t_game *g);

#endif
