/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:27:22 by lmorelli          #+#    #+#             */
/*   Updated: 2023/02/09 21:27:46 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_res(int fd, char *res)
{
	char	*temp;
	int		bytes;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(res, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		res = ft_strjoin(res, temp);
	}
	free (temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res[8192];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res[fd] = ft_read_res(fd, res[fd]);
	if (!res[fd])
		return (NULL);
	line = ft_write_line(res[fd]);
	res[fd] = ft_new_res(res[fd]);
	return (line);
}
