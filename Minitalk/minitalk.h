/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:50:10 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/29 01:58:00 by seohyuki         ###   ########.fr       */
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

int		ft_atoi(const char *str);

#endif
