/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:54 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/23 20:27:57 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	get_signal(int signum);

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = get_signal;
	pid = getpid();
	g_info.count = 0;
	g_info.letter = 0;
	ft_printf("%d", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}

void	get_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		g_info.count++;
	}
	if (signum == SIGUSR2)
	{
		g_info.letter += 1 << g_info.count;
		g_info.count++;
	}
	if (g_info.count == 12)
	{
		ft_printf("%c", g_info.letter);
		g_info.count = 0;
		g_info.letter = 0;
	}
}
