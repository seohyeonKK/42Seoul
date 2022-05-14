/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:37:09 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 01:35:22 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = (unsigned int)(ft_strlen(s));
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);

	i = 0;
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
