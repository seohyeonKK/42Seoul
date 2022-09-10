/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:00:52 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/10 22:00:22 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_print_char(char c);
int	ft_putnbr_fd(int n);
int	ft_putnbr_unsigned_fd(unsigned int n);
int	ft_putnbr_hexadecimal_fd(unsigned int n, char format);
int	ft_print_string(char *str);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexadecimal(unsigned int n, char format);
int	ft_print_pointer(unsigned int ptr);
int	ft_printf(const	char *str, ...);

#endif
