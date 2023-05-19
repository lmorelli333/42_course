/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:17:58 by lmorelli          #+#    #+#             */
/*   Updated: 2022/11/30 22:15:12 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	strlenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (i <= 1)
	{
		return (0);
	}
	return (i);
}

int	check(char *str)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127
			||str[i] == '+' || str[i] == '-' || str[i] == '\0')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenght;
	int	n;

	n = nbr;
	lenght = strlenght(base);
	if (check(base) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr < lenght)
		{
			ft_putchar(base[nbr]);
		}
		else
		{
			ft_putnbr_base(nbr / lenght, base);
			ft_putnbr_base(nbr % lenght, base);
		}
	}
}
