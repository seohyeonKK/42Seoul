/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:04:50 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/10 16:45:04 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	i;

	memory = (void *)malloc(count * size);
	if (memory == NULL)
		return (NULL);
	while (i < count * size)
	{
		*(((char *)memory) + i) = 0;
		i++;
	}
	return (memory);
}
