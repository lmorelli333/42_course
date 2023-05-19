/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:42:54 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/11 00:48:10 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	quit(void)
{
	exit(0);
}

void	window(t_all *box)
{
	int		i;

	i = 0;
	while (box->map.mapm[i])
		i++;
	box->map.mlx = mlx_init();
	box->map.window = mlx_new_window(box->map.mlx,
			(64 * ft_strlen(box->map.mapm[0])), (64 * (i) + 64), "so_long");
	mlx_hook(box->map.window, 17, 0, quit, 0);
}

void	take_img(t_all *box)
{
	box->img.player_r = mlx_xpm_file_to_image(box->map.mlx, "./img/playerR.xpm",
			&box->img.size_img, &box->img.size_img);
	box->img.player_l = mlx_xpm_file_to_image(box->map.mlx, "./img/playerL.xpm",
			&box->img.size_img, &box->img.size_img);
	box->img.enemy = mlx_xpm_file_to_image(box->map.mlx, "./img/enemyR.xpm",
			&box->img.size_img, &box->img.size_img);
	box->img.coll = mlx_xpm_file_to_image(box->map.mlx, "./img/coll.xpm",
			&box->img.size_img, &box->img.size_img);
	box->img.back = mlx_xpm_file_to_image(box->map.mlx, "./img/back.xpm",
			&box->img.size_img, &box->img.size_img);
	box->img.exit = mlx_xpm_file_to_image(box->map.mlx, "./img/exit.xpm",
			&box->img.size_img, &box->img.size_img);
	box->img.wall = mlx_xpm_file_to_image(box->map.mlx, "./img/wall.xpm",
			&box->img.size_img, &box->img.size_img);
}
