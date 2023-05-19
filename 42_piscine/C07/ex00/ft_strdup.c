/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:50:39 by lmorelli          #+#    #+#             */
/*   Updated: 2022/12/07 21:40:35 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (src[i])
	{
		len++;
		i++;
	}
	s = (char *) malloc(sizeof(char) * (len + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
