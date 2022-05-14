/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:44:55 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 01:21:27 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	find;

	i = 0;
	find = 0;
	while (s[i])
	{
		if (s[i] == c)
			find = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	if (s[find] == c)
		return ((char *)(s + find));
	return (NULL);
}
