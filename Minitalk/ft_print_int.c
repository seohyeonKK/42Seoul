/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:18:12 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/10 22:18:40 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int	length;

	length = ft_putnbr_fd(n);
	return (length);
}

int	ft_putnbr_fd(int n)
{
	int	length;

	length = 0;
	if (n / 10 != 0)
		length += ft_putnbr_fd(n / 10);
	if (n / 10 == 0 && n < 0)
		length += ft_print_char('-');
	n = n % 10;
	if (n < 0)
		n *= (-1);
	length += ft_print_char(n + '0');
	return (length);
}
