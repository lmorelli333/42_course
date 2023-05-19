/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:53:26 by lmorelli          #+#    #+#             */
/*   Updated: 2023/02/08 23:05:45 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *res, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
	}
	if (!res || !temp)
		return (NULL);
	j = 0;
	i = -1;
	str = malloc((ft_strlen(res) + ft_strlen(temp) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (res[++i])
		str[i] = res[i];
	while (temp[j])
		str[i++] = temp[j++];
	str[i] = '\0';
	str[ft_strlen(res) + ft_strlen(temp)] = '\0';
	free (res);
	return (str);
}

char	*ft_write_line(char *res)
{
	char	*line;
	int		i;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_res(char *res)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(res) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (res[i])
		s[j++] = res[i++];
	s[j] = '\0';
	free (res);
	return (s);
}
