/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:23:28 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/19 16:34:30 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signo, siginfo_t *info, void *context)
{
	static int	bit;
	static int	character;

	(void)context;
	if (signo == SIGUSR1)
		character += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	handler;

	pid = getpid();
	ft_printf("Server activated\nPID : %d\n", pid);
	handler.sa_sigaction = &ft_handler;
	handler.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	sigemptyset(&handler.sa_mask);
	while (1)
		pause();
}
