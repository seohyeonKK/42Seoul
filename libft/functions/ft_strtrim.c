/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:28:22 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 01:31:21 by seohyuki         ###   ########.fr       */
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

static size_t	get_end(size_t len, size_t start, char const *s1, char const *set)
{
	size_t	end;

	end = len - 1;
	while (start <= end && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
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
	end = get_end (len, start, s1, set);
	if (start > end)
		return (ft_strdup(""));
	size = end - start + 1;
	str = ((char *)malloc(sizeof(char) * (size + 1)));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, size + 1);
	return (str);
}
