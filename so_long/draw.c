/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:20:44 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 06:05:30 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
