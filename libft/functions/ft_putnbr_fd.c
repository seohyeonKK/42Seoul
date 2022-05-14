/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:11:52 by seohyuki          #+#    #+#             */
/*   Updated: 2022/05/14 20:43:07 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	if (n / 10 == 0 && n < 0)
		ft_putchar_fd('-', fd);
	n = n % 10;
	if (n < 0)
		n *= (-1);
	ft_putchar_fd(n + '0', fd);
}
