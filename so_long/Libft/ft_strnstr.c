/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:34:15 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 16:13:16 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_same(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && (i < len))
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str2[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (is_same(haystack + i, needle, len - i))
			{
				return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
