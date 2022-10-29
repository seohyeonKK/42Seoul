/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:35:00 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 04:11:40 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_string(t_game *g)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(g->move);
	while (i < g->col)
	{
		mlx_put_image_to_window(g->mlx, g->wnd, g->b, i * SIZE, 0 * SIZE);
		mlx_put_image_to_window(g->mlx, g->wnd, g->f, i * SIZE, 0 * SIZE);
		i++;
	}
	mlx_string_put(g->mlx, g->wnd, 10, 10, 0xff000000, str);
	free(str);
}

int key_hook(int key, t_game *g)
{
	int		i;
	int		j;

	i = g->p_i;
	j = g->p_j;
	if (key == W || key == A || key == S || key == D)
	{
		(g->move)++;
		printf("move_cnt = %d\n", g->move);
		draw_string(g);
	}
	if (key == 17 || key == 2)
		printf("exit");
	if (key == W)
		go(g, --i, j, g->w);
	else if (key == A)
		go(g, i, --j, g->a);
	else if (key == S)
		go(g, ++i, j, g->s);
	else if (key == D)
		go(g, i, ++j, g->d);
	else if (key == ESC)
		exit_game(0, g);
	return (0);
}

void go(t_game *g, int i, int j, void *img)
{
	int	x;
	int	y;

	x = g->p_j;
	y = g->p_i;
	if (g->map[i][j] == '0' || g->map[i][j] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->wnd, g->b, x * SIZE, y * SIZE);
		mlx_put_image_to_window(g->mlx, g->wnd, img, j * SIZE, i * SIZE);
		g->p_i = i;
		g->p_j = j;
		if (g->map[i][j] == 'C')
		{
			g->p_c++;
			g->map[i][j] = '0';
		}
	}
	if (g->map[i][j] == 'M')
		exit_game(0, g);
	if (g->map[i][j] == 'E')
	{
		if (g->c_cnt == g->p_c)
			exit_game(1, g);
	}
}

void sprite_img(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->wnd, g->b, j * SIZE, i * SIZE);
	if (g->spr % 2 == 0)
		mlx_put_image_to_window(g->mlx, g->wnd, g->m2, j * SIZE, i * SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->wnd, g->m, j * SIZE, i * SIZE);

}

int	sprite(t_game	*g)
{
	int	i;
	int	j;

	if (g->ani > 10000)
	{
		i = 0;
		while (i < g->row)
		{
			j = 0;
			while (j < g->col)
			{
				if (g->map[i][j] == 'M')
					sprite_img(g, i, j);
				j++;
			}
			i++;
		}
		g->spr++;
		g->ani = 0;
	}
	else
		g->ani++;
	return (0);
}

int	x_exit(t_game *g)
{
	exit_game(0, g);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	g;

	if (argc != 2)
		error();
	g.map = get_map(argv[1]);
	map_check(&g);
	object_check(&g);
	game_init(&g);
	draw_map(g);
	g.move = 0;
	mlx_key_hook(g.wnd, &key_hook, &g);
	g.ani = 0;
	g.spr = 0;
	mlx_loop_hook(g.mlx, &sprite, &g);
	mlx_hook(g.wnd, X_EVENT_KEY_EXIT, 0, &x_exit, &g);
	mlx_loop(g.mlx);
	return (0);
}

void	game_init(t_game	*g)
{
	int size;

	g->p_c = 0;
	size = SIZE;
	g->wnd_w = g->col * SIZE;
	g->wnd_h = g->row * SIZE;
	g->mlx = mlx_init();
	if (!g->mlx)
		free_error(g->map);
	g->wnd = mlx_new_window(g->mlx, g->wnd_w, g->wnd_h, "so_long");
	if (!g->wnd)
		free_error(g->map);
	g->w = mlx_xpm_file_to_image(g->mlx, "img/w.xpm", &size, &size);
	g->a = mlx_xpm_file_to_image(g->mlx, "img/a.xpm", &size, &size);
	g->s = mlx_xpm_file_to_image(g->mlx, "img/s.xpm", &size, &size);
	g->d = mlx_xpm_file_to_image(g->mlx, "img/d.xpm", &size, &size);
	g->b = mlx_xpm_file_to_image(g->mlx, "img/bg.xpm", &size, &size);
	g->f = mlx_xpm_file_to_image(g->mlx, "img/f.xpm", &size, &size);
	g->m = mlx_xpm_file_to_image(g->mlx, "img/m.xpm", &size, &size);
	g->m2 = mlx_xpm_file_to_image(g->mlx, "img/m2.xpm", &size, &size);
	g->c = mlx_xpm_file_to_image(g->mlx, "img/c.xpm", &size, &size);
	g->e = mlx_xpm_file_to_image(g->mlx, "img/e.xpm", &size, &size);
	if (!g->w || !g->a || !g->s || !g->d || !g->b || !g->f || !g->m || !g->m2
		|| !g->c || !g->e)
		free_error(g->map);
}

char	**get_map(char	*filename)
{
	char	*dot;
	int		map_file;
	char	**map;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		error();
	if (ft_strncmp(dot, ".ber", 5))
		error();
	map_file = open(filename, O_RDONLY);
	if (map_file == -1)
		error();
	map = make_map(map_file);
	close(map_file);
	return (map);
}

char	*read_map(int map_file)
{
	char	*map;
	char	*old;
	char	*line;

	map = NULL;
	line = get_next_line(map_file);
	if (line)
		map = ft_strjoin("", line);
	while (1)
	{
		free(line);
		line = get_next_line(map_file);
		if (line)
		{
			old = ft_strdup(map);
			free(map);
			map = ft_strjoin(old, line);
			free(old);
		}
		else
			break ;
	}
	return (map);
}

char	**make_map(int map_file)
{
	char	**map;
	char	*str;

	map = NULL;
	str = read_map(map_file);
	if (!str)
		error();
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

void	map_check(t_game	*g)
{
	int	idx;
	int	len;

	if (!g->map)
		error();
	g->col = ft_strlen(g->map[0]);
	idx = 1;
	while (g->map[idx])
	{
		len = ft_strlen(g->map[idx]);
		if (g->col != len)
			free_error(g->map);
		if (!wall_check(g->map[idx], 0, len))
			free_error(g->map);
		idx++;
	}
	if (!wall_check(g->map[0], 1, g->col))
		free_error(g->map);
	if (!wall_check(g->map[idx - 1], 1, g->col))
		free_error(g->map);
	g->row = idx;
}

int wall_check(char *str, int is_fr, int length)
{
	int	idx;

	idx = 0;
	if (is_fr)
	{
		while (idx < length)
		{
			if (str[idx] != '1')
				return (0);
			idx++;
		}
	}
	else
	{
		if (str[0] != '1' || str[length - 1] != '1')
			return (0);
	}
	return (1);
}

void	error(void)
{
	printf("Error\n");
	system("leaks so_long");
	exit(1);
}

void	free_error(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	printf("Error\n");
	system("leaks so_long");
	exit(1);
}

void object_check(t_game *g)
{
	cnt_object(g);
	if (g->p_cnt != 1)
		free_error(g->map);
	if (g->e_cnt != 1)
		free_error(g->map);
	if (g->c_cnt < 1)
		free_error(g->map);
	if (g->m_cnt < 1)
		free_error(g->map);
}

void cnt_object(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	g->p_cnt = 0;
	g->e_cnt = 0;
	g->c_cnt = 0;
	g->m_cnt = 0;
	while (i < g->row)
	{
		j = 0;
		while (j < g->col)
		{
			check_object_type(g->map[i][j], g, i, j);
			j++;
		}
		i++;
	}
}

void check_object_type(char ch, t_game *g, int i, int j)
{
	if (ch == 'P')
	{
		g->p_cnt++;
		g->p_i = j;
		g->p_j = i;
		g->map[i][j] = '0';
	}
	if (ch == 'C')
		g->c_cnt++;
	if (ch == 'E')
		g->e_cnt++;
	if (ch == 'M')
		g->m_cnt++;
}

void draw_map(t_game g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g.row)
	{
		j = 0;
		while (j < g.col)
		{
			put_img(g, j * (SIZE), i * (SIZE), g.map[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(g.mlx, g.wnd, g.s, g.p_j * SIZE, g.p_i * SIZE);
}

void put_img(t_game g, int x, int y, char ch)
{
	mlx_put_image_to_window(g.mlx, g.wnd, g.b, x, y);
	if (ch == '1')
		mlx_put_image_to_window(g.mlx, g.wnd, g.f, x, y);
	if (ch == 'C')
		mlx_put_image_to_window(g.mlx, g.wnd, g.c, x, y);
	if (ch == 'E')
		mlx_put_image_to_window(g.mlx, g.wnd, g.e, x, y);
	if (ch == 'M')
		mlx_put_image_to_window(g.mlx, g.wnd, g.m, x, y);
}

void exit_game(int win, t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		free(g->map[i++]);
	free(g->map);
	if (win)
		printf("you win!\n");
	else
		printf("you lose!\n");
	system("leaks so_long");
	destroy(g);
	exit(0);
}

void destroy(t_game *g)
{
	mlx_destroy_image(g->mlx, g->w);
	mlx_destroy_image(g->mlx, g->a);
	mlx_destroy_image(g->mlx, g->s);
	mlx_destroy_image(g->mlx, g->d);
	mlx_destroy_image(g->mlx, g->b);
	mlx_destroy_image(g->mlx, g->f);
	mlx_destroy_image(g->mlx, g->m);
	mlx_destroy_image(g->mlx, g->m2);
	mlx_destroy_image(g->mlx, g->e);
	mlx_destroy_image(g->mlx, g->c);
	mlx_destroy_window(g->mlx, g->wnd);
}
