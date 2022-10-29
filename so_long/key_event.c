/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:17:57 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 06:04:53 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *g)
{
	int		i;
	int		j;

	i = g->p_i;
	j = g->p_j;
	if (key == W || key == A || key == S || key == D)
	{
		(g->move)++;
		printf("move : %d\n", g->move);
	}
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

void	go(t_game *g, int i, int j, void *img)
{
	int	x;
	int	y;

	x = g->p_j;
	y = g->p_i;
	mlx_put_image_to_window(g->mlx, g->wnd, g->b, x * SIZE, y * SIZE);
	mlx_put_image_to_window(g->mlx, g->wnd, img, x * SIZE, y * SIZE);
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
	if (g->map[i][j] == 'E')
		if (g->c_cnt == g->p_c)
			exit_game(1, g);
}
