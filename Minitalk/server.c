/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:54 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/29 14:10:30 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	get_signal(int signum, siginfo_t *info, void *ucontext);
void	print_letter(int signum);
void	error_exit(void);

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_signal;
	pid = getpid();
	g_info.c_pid = -1;
	g_info.count = 0;
	g_info.letter = 0;
	g_info.pid = pid;
	g_info.signal_cnt = 0;
	ft_printf("server pid = %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}

void	get_signal(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_info.c_pid == -1)
	{
		g_info.c_pid = info->si_pid;
		g_info.signal_cnt = 0;
		ft_printf("client %d and server %d", g_info.c_pid, g_info.pid);
		ft_printf(" connected!\n");
		print_letter(signum);
	}
	else if (g_info.c_pid == info->si_pid)
		print_letter(signum);
}

void	print_letter(int signum)
{
	if (signum == SIGUSR1)
		g_info.count++;
	else if (signum == SIGUSR2)
	{
		g_info.letter += (1 << g_info.count);
		g_info.count++;
	}
	g_info.signal_cnt++;
	if (kill(g_info.c_pid, SIGUSR1) != 0)
		error_exit();
	if (g_info.count == BITLEN)
	{
		if (g_info.letter == 0)
		{
			ft_printf("\n");
			ft_printf("server recieved %d signals\n", g_info.signal_cnt);
			g_info.c_pid = -1;
		}
		else
			ft_printf("%c", g_info.letter);
		g_info.count = 0;
		g_info.letter = 0;
	}
}

void	error_exit(void)
{
	ft_printf("server error\n");
	exit(1);
}
