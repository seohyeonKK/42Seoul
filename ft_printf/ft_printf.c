/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:58:11 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/10 21:49:09 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
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

int	ft_putnbr_unsigned_fd(unsigned int n)
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

int	ft_putnbr_hexadecimal_fd(unsigned long n, char format)
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

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int n)
{
	int	length;

	length = ft_putnbr_fd(n);
	return (length);
}

int	ft_print_unsigned(unsigned int n)
{
	int	length;

	length = ft_putnbr_unsigned_fd(n);
	return (length);
}

int	ft_print_hexadecimal(unsigned int n, char format)
{
	int	length;

	length = ft_putnbr_hexadecimal_fd(n, format);
	return (length);
}

int	ft_print_pointer(unsigned long ptr)
{
	int	length;

	length = 0;
	write(1, "0x", 2);
	length += 2;
	if (ptr == 0)
		length += ft_print_char('0');
	else
		length += ft_putnbr_hexadecimal_fd(ptr, 'x');
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
			if (*str == 'c')
				length += ft_print_char(va_arg(ap, int));
			else if (*str == 's')
				length += ft_print_string(va_arg(ap, char *));
			else if (*str == 'd' || *str == 'i')
				length += ft_print_int(va_arg(ap, int));
			else if (*str == 'u')
				length += ft_print_unsigned(va_arg(ap, unsigned int));
			else if (*str == 'x' || *str == 'X')
				length += ft_print_hexadecimal(va_arg(ap, unsigned int), *str);
			else if (*str == 'p')
				length += ft_print_pointer(va_arg(ap, unsigned long));
			else if (*str == '%')
				length += ft_print_char('%');
		}
		else
			length += ft_print_char(*str);
		str++;
	}
	return (length);
}
