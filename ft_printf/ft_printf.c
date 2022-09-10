/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:58:11 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/10 22:30:45 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(const char *str, va_list *ap)
{
	int	length;

	length = 0;
	if (*str == 'c')
		length += ft_print_char(va_arg(*ap, int));
	else if (*str == 's')
		length += ft_print_string(va_arg(*ap, char *));
	else if (*str == 'd' || *str == 'i')
		length += ft_print_int(va_arg(*ap, int));
	else if (*str == 'u')
		length += ft_print_unsigned(va_arg(*ap, unsigned int));
	else if (*str == 'x' || *str == 'X')
		length += ft_print_hexadecimal(va_arg(*ap, unsigned int), *str);
	else if (*str == 'p')
		length += ft_print_pointer(va_arg(*ap, unsigned long));
	else if (*str == '%')
		length += ft_print_char('%');
	return (length);
}

int	ft_printf(const	char *str, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			length += format(str, &ap);
		}
		else
			length += ft_print_char(*str);
		str++;
	}
	return (length);
}
