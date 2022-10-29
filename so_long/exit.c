/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:24:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 06:05:08 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_exit(t_game *g)
{
	exit_game(0, g);
	return (0);
}

void	exit_game(int win, t_game *g)
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

void	destroy(t_game *g)
{
	mlx_destroy_image(g->mlx, g->w);
	mlx_destroy_image(g->mlx, g->a);
	mlx_destroy_image(g->mlx, g->s);
	mlx_destroy_image(g->mlx, g->d);
	mlx_destroy_image(g->mlx, g->b);
	mlx_destroy_image(g->mlx, g->f);
	mlx_destroy_image(g->mlx, g->e);
	mlx_destroy_image(g->mlx, g->c);
	mlx_destroy_window(g->mlx, g->wnd);
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
