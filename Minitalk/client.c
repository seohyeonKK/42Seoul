/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/26 21:50:20 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(void);

int	main(int argc, char *argv[])
{
	int		pid;
	int		idx;
	int		sub_idx;
	char	*str;
	char	elem;

	if (argc != 3)
		error_exit();
	pid = ft_atoi(argv[1]);
	idx = 0;
	str = argv[2];

	while (str[idx] != '\0')
	{
		sub_idx = 0;
		elem = str[idx];
		while (sub_idx < BITLEN)
		{
			if ((elem & (1 << sub_idx)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			sub_idx++;
		}
		idx++;
	}
}

void	error_exit(void)
{
	ft_printf("error\n");
	exit(1);
}
