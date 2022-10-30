/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:22:13 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/30 14:28:41 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	alloc_error(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	printf("Error\n");
	exit(1);
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
	map = ft_strdup("");
	if (!map)
		alloc_error(line, 0);
	while (line)
	{
		old = ft_strdup(map);
		if (!old)
			alloc_error(map, line);
		free(map);
		map = ft_strjoin(old, line);
		if (!map)
			alloc_error(old, line);
		free(old);
		free(line);
		line = get_next_line(map_file);
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
