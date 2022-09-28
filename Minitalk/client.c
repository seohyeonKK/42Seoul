/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/29 00:26:39 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(void);
void	send_char(int pid, char ch, int *cnt);
void	handler(int signum);

int	main(int argc, char *argv[])
{
	int		pid;
	int		idx;
	char	*str;
	int		signal_cnt;

	if (argc != 3)
		error_exit();
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		error_exit();
	signal_cnt = 0;
	idx = 0;
	str = argv[2];
	while (str[idx])
	{
		signal(SIGUSR1, handler);
		send_char(pid, str[idx++], &signal_cnt);
	}
	send_char(pid, '\0', &signal_cnt);
	ft_printf("client %d sent %d signals\n", getpid(), signal_cnt);
}

void	error_exit(void)
{
	ft_printf("client error\n");
	exit(1);
}

void	send_char(int pid, char ch, int *cnt)
{
	int	idx;

	idx = 0;
	while (idx < BITLEN)
	{
		if ((ch & (1 << idx)) == 0)
		{
			if (kill(pid, SIGUSR1) != 0)
				error_exit();
			(*cnt)++;
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				error_exit();
			(*cnt)++;
		}
		pause();
		usleep(100);
		idx++;
	}
}

void	handler(int signum)
{
	if (signum != SIGUSR1)
		error_exit();
}
