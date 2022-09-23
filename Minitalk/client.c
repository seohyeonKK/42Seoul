/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/23 18:34:02 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int		pid;
	int		idx;
	int		sub_idx;
	char	*str;
	char	elem;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	idx = 0;
	str = argv[2];
	while (str[idx] != '\0')
	{
		sub_idx = 0;
		elem = str[idx];
		while (sub_idx < 12)
		{
			if ((elem & (1 << sub_idx)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(8);
			sub_idx++;
		}
		idx++;
	}
}
