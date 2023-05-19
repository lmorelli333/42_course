/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:02:03 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/11 01:38:20 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img02(int i, int j, t_all *box)
{
	if (box->map.mapm[i][j] == 'E')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->img.exit, j * 64, (i + 1) * 64);
	else if (box->map.mapm[i][j] == 'C')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->img.coll, j * 64, (i + 1) * 64);
	else if (box->map.mapm[i][j] == 'N')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->img.enemy, j * 64, (i + 1) * 64);
	else if (box->map.mapm[i][j] == 'P')
		mlx_put_image_to_window(box->map.mlx, box->map.window,
			box->img.current_player, j * 64, (i + 1) * 64);
}

void	put_img01(t_all *box)
{
	int	i;
	int	j;

	i = -1;
	while (box->map.mapm[++i])
	{
		j = -1;
		while (box->map.mapm[i][++j])
		{
			if (box->map.mapm[i][j] == '1')
				mlx_put_image_to_window(box->map.mlx, box->map.window,
					box->img.wall, j * 64, (i + 1) * 64);
			else if (box->map.mapm[i][j] == '0')
				mlx_put_image_to_window(box->map.mlx, box->map.window,
					box->img.back, j * 64, (i + 1) * 64);
			else if (box->map.mapm[i][j] == 'E' || box->map.mapm[i][j] == 'C'
				|| box->map.mapm[i][j] == 'N' || box->map.mapm[i][j] == 'P')
				put_img02(i, j, box);
		}
	}
}

int	enemy_patrol(t_all *box)
{
	if (box->moves.patrol < 7000)
	{
		box->moves.patrol++;
		return (0);
	}
	box->moves.patrol = 0;
	if (box->img.patrol_flag == 1)
		box->img.enemy = mlx_xpm_file_to_image(box->map.mlx,
				"./img/enemyL.xpm", &box->img.size_img,
				&box->img.size_img);
	else
	{
		box->img.enemy = mlx_xpm_file_to_image(box->map.mlx,
				"./img/enemyR.xpm", &box->img.size_img,
				&box->img.size_img);
		box->img.patrol_flag = 0;
	}
	put_img01(box);
	box->img.patrol_flag++;
	return (0);
}
