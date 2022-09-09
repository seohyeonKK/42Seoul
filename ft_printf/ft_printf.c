/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:58:11 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/09 21:12:05 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10);
	if (n / 10 == 0 && n < 0)
		ft_print_char('-');
	n = n % 10;
	if (n < 0)
		n *= (-1);
	ft_print_char(n + '0');
}

void	ft_putnbr_unsigned_fd(unsigned int n)
{
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10);
	if (n / 10 == 0 && n < 0)
		ft_print_char('-');
	n = n % 10;
	if (n < 0)
		n *= (-1);
	ft_print_char(n + '0');
}

void	ft_putnbr_hexadecimal_fd(unsigned int n, char format)
{
	if (n / 16 != 0)
		ft_putnbr_hexadecimal_fd(n / 16, format);
	n = n % 16;
	if (n <= 9)
		ft_print_char(n + '0');
	else
	{
		if (format == 'x')
			ft_print_char(n - 10 + 'a');
		else
			ft_print_char(n - 10 + 'A');
	}
}

void	ft_print_string(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_print_int(int n)
{
	ft_putnbr_fd(n);
}

void	ft_print_unsigned(unsigned int n)
{
	ft_putnbr_unsigned_fd(n);
}

void	ft_print_hexadecimal(unsigned int n, char format)
{
	ft_putnbr_hexadecimal_fd(n, format);
}

void	ft_print_pointer(unsigned int ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
		write(1, "0", 1);
	else
	{
		write(1, "1", 1);
		ft_putnbr_hexadecimal_fd(ptr, 'x');
	}
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
				ft_print_char(va_arg(ap, int));
			else if (*str == 's')
				ft_print_string(va_arg(ap, char *));
			else if (*str == 'd' || *str == 'i')
				ft_print_int(va_arg(ap, int));
			else if (*str == 'u')
				ft_print_unsigned(va_arg(ap, unsigned int));
			else if (*str == 'x' || *str == 'X')
				ft_print_hexadecimal(va_arg(ap, unsigned int), *str);
			else if (*str == 'p')
				ft_print_pointer(va_arg(ap, unsigned int));
			else if (*str == '%')
				ft_print_char('%');
		}
		else
			ft_print_char(*str);
		str++;
	}

	return (0);
}

int main(void)
{
	char str = 'a';
	int num = 123;
	// printf("%c");
	// printf("%%\nhello world!\n", -2147483649);
	// ft_printf("%%\nhello world!\n", -2147483649);
	printf("%p\n", &num);
	ft_printf("%p", &num);

	// printf("%s", NULL);
}
