/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:20:44 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 04:26:32 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	sprite_img(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->wnd, g->b, j * SIZE, i * SIZE);
	if (g->spr % 2 == 0)
		mlx_put_image_to_window(g->mlx, g->wnd, g->m2, j * SIZE, i * SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->wnd, g->m, j * SIZE, i * SIZE);
}

void	draw_map(t_game g)
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

void	put_img(t_game g, int x, int y, char ch)
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
