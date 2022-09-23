/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeon <seohyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:50:16 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/23 18:03:58 by seohyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(const char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\v' || ch == '\f'
		|| ch == '\r')
		return (1);
	return (0);
}

int	ft_initialize(const char *str, int *sign)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		*sign = (-1);
		i++;
	}
	return (i);
}

int	check_invalid(long answer, long tmp)
{
	if (answer < tmp)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	answer;
	long	tmp;
	int		sign;

	i = 0;
	answer = 0;
	sign = 1;
	i = ft_initialize(str, &sign);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return ((int)(sign * answer));
		tmp = answer;
		answer = answer * 10 + (str[i] - '0');
		if (check_invalid(answer, tmp))
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return ((int)(sign * answer));
}
