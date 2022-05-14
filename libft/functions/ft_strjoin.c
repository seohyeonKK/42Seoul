/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:51:09 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 01:30:02 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_length;
	size_t	s2_length;
	size_t	length;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	length = s1_length + s2_length;

	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);

	ft_memmove(str, s1, s1_length);
	ft_memmove(str + s1_length, s2, s2_length);
	str[length] = '\0';

	return (str);
}
