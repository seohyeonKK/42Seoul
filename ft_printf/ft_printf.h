/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeon <seohyeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:00:52 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/12 19:59:40 by seohyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_putnbr_fd(int n);
int	ft_putnbr_unsigned_fd(unsigned int n);
int	ft_putnbr_hexadecimal_fd(unsigned int n, char format);
int	ft_putnbr_pointer_fd(size_t n);
int	ft_print_string(char *str);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexadecimal(unsigned int n, char format);
int	ft_print_pointer(size_t ptr);
int	format(const char *str, va_list *ap);
int	ft_printf(const	char *str, ...);

#endif
