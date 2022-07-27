/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:23:09 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 17:42:30 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_string_count(char const *s, char c, unsigned int *len)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	cnt;

	start = 0;
	cnt = 0;
	while (s[start] && s[start] == c)
		start++;
	end = start;
	while (s[end])
	{
		if (s[end] == c && end > start)
		{
			cnt++;
			start = end + 1;
			while (s[start] == c)
				start++;
			end = start - 1;
		}
		end++;
	}
	if (end > 0 && (s[end - 1] != '\0' && s[end - 1] != c))
		cnt++;
	*len = end;
	return (cnt);
}

static void	free_all(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*create_str(char const *s, unsigned int start, unsigned int len)
{
	char	*str;

	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static void	get_strings(char **arr, unsigned int length, char const *s, char c)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	idx;

	start = 0;
	idx = 0;
	while (s[start] && s[start] == c)
		start++;
	end = start;
	while (end <= length)
	{
		if ((s[end] == '\0' || s[end] == c) && end > start)
		{
			arr[idx] = create_str(s, start, end - start);
			if (!arr[idx])
				return (free_all(arr));
			idx++;
			start = end + 1;
			while (start < length && s[start] == c)
				start++;
			end = start;
		}
		end ++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	count;
	unsigned int	length;

	if (!s)
		return (NULL);
	count = get_string_count(s, c, &length);
	arr = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	get_strings(arr, length, s, c);
	return (arr);
}
