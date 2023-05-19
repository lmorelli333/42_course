/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:05:27 by lmorelli          #+#    #+#             */
/*   Updated: 2022/12/07 21:31:01 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	j = 0;
	k = 0;
	p = malloc(sizeof(strs));
	while (j < size)
	{
		i = 0;
		while (strs[j][i] != '\0')
		{
			p[k++] = strs[j][i++];
		}
		i = 0;
		while (sep[i] != '\0' && j != size - 1)
		{
			p[k++] = sep[i++];
		}
		j++;
	}
	p[k] = '\0';
	return (p);
}
