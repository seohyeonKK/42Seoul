/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:54 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/23 18:36:00 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	one(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("z");
	if (signum == SIGUSR2)
		ft_printf("b");
}

int	main(void)
{
	int	pid;
	struct sigaction sa;

	sa.sa_handler = one;


	pid = getpid();
	ft_printf("%d", pid);
	while (1)
	{
		// 100 -> 1000 ms
		// 1 -> 10ms

		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		// signal(SIGUSR2, two);
		pause();
	}
	return (0);
}
