/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:29:17 by seohyuki          #+#    #+#             */
/*   Updated: 2022/08/15 16:38:06 by seohyuki         ###   ########.fr       */
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
	while (!ft_strchr(*str, '\n') && byte)
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
	static char		*str[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				byte;
	char			*line;
	char			*old;

	if (BUFFER_SIZE <= 0)
		return (0);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte == -1 || (byte == 0 && str[fd] == NULL))
		return (0);
	buf[byte] = '\0';
	if (byte && str[fd])
	{
		old = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		free(old);
	}
	if (byte && !str[fd])
		str[fd] = ft_strjoin("", buf);
	line = get_line(fd, &str[fd]);
	str[fd] = update_string(str[fd]);
	return (line);
}
