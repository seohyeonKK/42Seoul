/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:13:26 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 01:28:56 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned int start, size_t len, size_t n)
{
	size_t	size;

	if (start >= n)
		size = 0;
	else if (n - start < len)
		size = n - start;
	else
		size = len;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);

	n = ft_strlen(s);

	size = get_size(start, len, n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);

	i = 0;
	while (i < size)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';

	return (str);
}
