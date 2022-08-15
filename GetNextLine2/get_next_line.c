/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:29:17 by seohyuki          #+#    #+#             */
/*   Updated: 2022/08/15 16:08:02 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char **str, unsigned int *idx)
{
	char	*line;
	size_t	len;
	char	buf[BUFFER_SIZE + 1];
	char	*old;
	int		byte;

	*idx = 0;
	if (!*str)
		return (0);
	len = ft_strlen(*str);
	if (len == 0)
		return (0);
	byte = 1;
	while (!ft_strchr(*str, '\n') && byte)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		buf[byte] = '\0';
		old = *str;
		*str = ft_strjoin(*str, buf);
		free(old);
	}
	while ((*str)[*idx] != '\n' && (*str)[*idx] != '\0')
		(*idx)++;
	line = (char *)malloc(sizeof(char) * ((*idx) + 2));
	// line = NULL;
	if (!line)
		return (0);
	ft_memmove(line, *str, (*idx) + 1);
	line[*idx + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			buf[BUFFER_SIZE + 1];
	int				byte;
	char			*line;
	unsigned int	idx;
	char			*old;

	if (BUFFER_SIZE <= 0)
		return (0);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte == -1 || (byte == 0 && str == NULL))
		return (0);
	buf[byte] = '\0';
	if (byte)
	{
		if (!str)
			str = ft_strjoin("", buf);
		else
		{
			old = str;
			str = ft_strjoin(str, buf);
			free(old);
		}
	}
	line = get_line(fd, &str, &idx);
	str = update_string(str, idx);
	return (line);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int fd = open("./only_nl.txt", O_RDONLY);
// 	while (1)
// 	{
// 		char *str = get_next_line(fd);
// 		if (str == NULL) break;
// 		printf("%s..", str);
// 	}
// 	return (0);
// }
