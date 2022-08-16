/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:29:17 by seohyuki          #+#    #+#             */
/*   Updated: 2022/08/16 12:34:25 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char **str)
{
	char	*line;
	char	buf[BUFFER_SIZE + 1];
	char	*old;
	int		byte;
	int		idx;

	idx = 0;
	if (!*str || !ft_strlen(*str))
		return (0);
	byte = 1;
	while (!ft_strchr(*str, '\n') && byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		buf[byte] = '\0';
		old = *str;
		*str = ft_strjoin(*str, buf);
		free(old);
	}
	while ((*str)[idx] != '\n' && (*str)[idx] != '\0')
		(idx)++;
	line = (char *)malloc(sizeof(char) * ((idx) + 2));
	ft_memmove(line, *str, (idx) + 1);
	line[idx + 1] = '\0';
	return (line);
}

char	*update_string(char *str)
{
	size_t			len;
	char			*new;
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\n' && str[idx] != '\0')
		(idx)++;
	len = ft_strlen(str);
	if (len > (size_t)idx + 1)
	{
		new = ft_strjoin(str + idx + 1, "");
		free(str);
		str = new;
	}
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			buf[BUFFER_SIZE + 1];
	int				byte;
	char			*line;
	char			*old;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte == -1 || (byte == 0 && str == NULL))
		return (0);
	buf[byte] = '\0';
	if (byte && str)
	{
		old = str;
		str = ft_strjoin(str, buf);
		free(old);
	}
	if (byte && !str)
		str = ft_strjoin("", buf);
	line = get_line(fd, &str);
	str = update_string(str);
	return (line);
}
