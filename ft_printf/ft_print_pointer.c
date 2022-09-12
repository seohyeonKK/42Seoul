/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeon <seohyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:15:53 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/12 19:59:27 by seohyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pointer_fd(size_t n)
{
	int	length;

	length = 0;
	if (n / 16 != 0)
		length += ft_putnbr_pointer_fd(n / 16);
	n = n % 16;
	if (n <= 9)
		length += ft_print_char(n + '0');
	else
		length += ft_print_char(n - 10 + 'a');
	return (length);
}

int	ft_print_pointer(size_t ptr)
{
	int	length;

	length = 0;
	write(1, "0x", 2);
	length += 2;
	if (ptr == 0)
		length += ft_print_char('0');
	else
		length += ft_putnbr_pointer_fd(ptr);
	return (length);
}
