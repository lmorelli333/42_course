/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:45:20 by lmorelli          #+#    #+#             */
/*   Updated: 2022/11/22 19:57:45 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	split(int a, int b)
{
	int	stop;

	stop = 0;
	if (a == 98)
	{
		stop = 1;
	}
	ft_putchar (48 + a / 10);
	ft_putchar (48 + a % 10);
	ft_putchar (' ');
	ft_putchar (48 + b / 10);
	ft_putchar (48 + b % 10);
	if (stop != 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			split(a, b);
			b++;
		}
		a++;
	}
}
