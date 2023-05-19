/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:17:47 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/10 20:12:37 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *av, t_all *box)
{
	int		fd;
	char	*str;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return ;
	box->map.mapv = malloc(1);
	box->map.mapv[0] = '\0';
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		box->map.mapv = ft_strjoin(box->map.mapv, str);
		free(str);
	}
	box->map.mapm = ft_split(box->map.mapv, '\n');
	close(fd);
}

void	enemy_position(t_all *box)
{
	int	r;
	int	c;

	r = 1;
	while (box->map.mapm[r])
	{
		c = 1;
		while (box->map.mapm[r][c])
		{
			if (box->map.mapm[r][c] == 'N')
			{
				box->moves.y = r;
				box->moves.x = c;
				break ;
			}
			c++;
		}
		r++;
	}
}

void	player_position(t_all *box)
{
	int	r;
	int	c;

	r = 1;
	enemy_position(box);
	while (box->map.mapm[r])
	{
		c = 1;
		while (box->map.mapm[r][c])
		{
			if (box->map.mapm[r][c] == 'P')
			{
				box->moves.i = r;
				box->moves.j = c;
				break ;
			}
			c++;
		}
		r++;
	}
}

void	remaining_collect(t_all *box)
{
	int	i;
	int	j;

	i = 1;
	box->img.victory_obj = 0;
	while (box->map.mapm[i])
	{
		j = 1;
		while (box->map.mapm[i][j])
		{
			if (box->map.mapm[i][j] == 'C')
				box->img.victory_obj++;
			j++;
		}
		i++;
	}
}
