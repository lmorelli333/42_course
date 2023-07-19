/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:26:11 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 19:40:26 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sign(char c)
{
	return (c == '+' || c == '-');
}

static int	check_nb(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

static int	same_nb(char **av)
{
	int	same;
	int	i;
	int	j;

	same = 0;
	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			same = ft_strcmp(av[i], av[j]);
			if (same == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	zero_counter(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_av(char **av, int flag)
{
	int	i;
	int	zeros;

	if (flag == 1)
		i = 0;
	else
		i = 1;
	zeros = 0;
	while (av[i])
	{
		if (!check_nb(av[i]))
			return (0);
		zeros += zero_counter(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (same_nb(av))
		return (0);
	return (1);
}
