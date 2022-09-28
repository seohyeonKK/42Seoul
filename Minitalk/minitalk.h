/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:50:10 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/28 20:33:18 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

# define BITLEN 8

typedef struct s_info{
	int	count;
	int	letter;
	int	c_pid;
	int	pid;
	int	signal_cnt;
}	t_info;

int	ft_atoi(const char *str);
int	check_invalid(long answer, long tmp);
int	ft_initialize(const char *str, int *sign);
int	ft_isspace(const char ch);
void	error_exit(void);

#endif
