/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:25:54 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/19 17:11:09 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(char c, int pid, int bit)
{
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(1250);
	}
}

void	take_bit(char *message, int pid)
{
	int	i;
	int	bit;

	i = -1;
	while (message[++i])
	{
		bit = 0;
		send_byte(message[i], pid, bit);
	}
}

void	print_ok(int empty)
{
	(void)empty;
	ft_printf("The message has been sent successfully\n");
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Error\n");
		exit (0);
	}
	pid = ft_atoi(av[1]);
	take_bit(av[2], pid);
	signal(SIGUSR1, &print_ok);
	send_byte('\n', pid, 0);
	send_byte('\0', pid, 0);
}
