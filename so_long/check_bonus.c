/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:19:25 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 05:55:56 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	wall_check(char *str, int is_fr, int length)
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

void	object_check(t_game *g)
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

void	cnt_object(t_game *g)
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

void	check_object_type(char ch, t_game *g, int i, int j)
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
