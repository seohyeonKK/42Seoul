/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:28:22 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 17:50:51 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(size_t len, char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static size_t	get_end(size_t len, size_t s, char const *s1, char const *set)
{
	size_t	e;

	e = len - 1;
	while (s <= e && ft_strchr(set, s1[e]))
		e--;
	return (e);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	e;
	size_t	len;
	size_t	size;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	start = get_start(len, s1, set);
	e = get_end (len, start, s1, set);
	if (start > e)
		return (ft_strdup(""));
	size = e - start + 1;
	str = ((char *)malloc(sizeof(char) * (size + 1)));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, size + 1);
	return (str);
}
