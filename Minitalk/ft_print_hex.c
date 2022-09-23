/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:19:40 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/10 22:32:25 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexadecimal_fd(unsigned int n, char format)
{
	int	length;

	length = 0;
	if (n / 16 != 0)
		length += ft_putnbr_hexadecimal_fd(n / 16, format);
	n = n % 16;
	if (n <= 9)
		length += ft_print_char(n + '0');
	else
	{
		if (format == 'x')
			length += ft_print_char(n - 10 + 'a');
		else
			length += ft_print_char(n - 10 + 'A');
	}
	return (length);
}

int	ft_print_hexadecimal(unsigned int n, char format)
{
	int	length;

	length = ft_putnbr_hexadecimal_fd(n, format);
	return (length);
}
