/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:50:16 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/09 14:48:13 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\v' || ch == '\f'
		|| ch == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	answer;
	int			sign;

	i = 0;
	answer = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = (-1);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (sign * answer);
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	return (sign * answer);
}

// #include <stdio.h>

// int	main(void)
// {
// 	long long a = atoi("429496876999997399999999900");
// 	long long  b = ft_atoi("429496876999997399999999900");

// 	// a = atoi("-31-uuyi3214");
// 	// b = ft_atoi("-31-uuyi3214");

// 	printf("%lld\n", a);
// 	printf("%lld", b);

// 	return (0);
// }
