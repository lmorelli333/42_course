/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:27:06 by lmorelli          #+#    #+#             */
/*   Updated: 2022/12/05 22:03:49 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*s;
	int	len;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	s = malloc(len * sizeof(int));
	if (s == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = s;
	while (i < len)
	{
		s[i] = min + i;
		i++;
	}
	return (len);
}
