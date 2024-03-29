/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:35:00 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 05:55:49 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int	size;

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
