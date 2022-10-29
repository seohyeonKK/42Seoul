/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:22:13 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 06:03:55 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		i;

	map = NULL;
	str = read_map(map_file);
	if (!str)
		error();
	i = 0;
	while (str[i])
	{
		if (str[0] == '\n'
			|| (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n'))
		{
			free(str);
			error();
		}
		i++;
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
