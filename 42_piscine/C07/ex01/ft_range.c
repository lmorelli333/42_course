/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:19:42 by lmorelli          #+#    #+#             */
/*   Updated: 2022/12/07 21:43:57 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	len;
	int	i;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		return (NULL);
	}
	range = (int *)malloc(len * sizeof(int));
	if (range == NULL)
	{
		return (0);
	}
	while (i < len)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
