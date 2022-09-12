/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:19:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/12 20:03:39 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	length;

	length = ft_putnbr_unsigned_fd(n);
	return (length);
}

int	ft_putnbr_unsigned_fd(unsigned int n)
{
	int	length;

	length = 0;
	if (n / 10 != 0)
		length += ft_putnbr_fd(n / 10);
	n = n % 10;
	length += ft_print_char(n + '0');
	return (length);
}
