/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:20:53 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/15 17:51:03 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_size(int n)
{
	unsigned int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	ft_putnbr(char *str, unsigned int size, int n)
{
	int	last;

	str[size] = '\0';
	last = n % 10;
	n /= 10;
	if (n < 0 || last < 0)
	{
		last *= (-1);
		str[0] = '-';
		n *= (-1);
	}
	str[--size] = last + '0';
	while (n != 0)
	{
		str[--size] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*str;

	if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_putnbr(str, size, n);
	return (str);
}
