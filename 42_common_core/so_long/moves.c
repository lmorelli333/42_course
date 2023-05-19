/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:02:24 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/11 01:37:11 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i - 1][box->moves.j] == '0' ||
		box->map.mapm[box->moves.i - 1][box->moves.j] == 'C')
	{
		if (box->map.mapm[box->moves.i - 1][box->moves.j] == 'C')
		{
			box->img.victory_obj--;
			if (box->img.victory_obj == 0)
				box->img.exit = mlx_xpm_file_to_image(box->map.mlx,
						"./img/E2.xpm", &box->img.size_img, &box->img.size_img);
		}
		box->map.mapm[box->moves.i - 1][box->moves.j] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i - 1][box->moves.j] == 'E')
	{
		if (box->img.victory_obj == 0)
			exit (0);
	}
	else if (box->map.mapm[box->moves.i - 1][box->moves.j] == 'N')
		exit (0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

void	move_down(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i + 1][box->moves.j] == '0' ||
		box->map.mapm[box->moves.i + 1][box->moves.j] == 'C')
	{
		if (box->map.mapm[box->moves.i + 1][box->moves.j] == 'C')
		{
			box->img.victory_obj--;
			if (box->img.victory_obj == 0)
				box->img.exit = mlx_xpm_file_to_image(box->map.mlx,
						"./img/E2.xpm", &box->img.size_img, &box->img.size_img);
		}
		box->map.mapm[box->moves.i + 1][box->moves.j] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i + 1][box->moves.j] == 'E')
	{
		if (box->img.victory_obj == 0)
			exit (0);
	}
	else if (box->map.mapm[box->moves.i + 1][box->moves.j] == 'N')
		exit (0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

void	move_left(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i][box->moves.j - 1] == '0' ||
		box->map.mapm[box->moves.i][box->moves.j - 1] == 'C')
	{
		if (box->map.mapm[box->moves.i][box->moves.j - 1] == 'C')
		{
			box->img.victory_obj--;
			if (box->img.victory_obj == 0)
				box->img.exit = mlx_xpm_file_to_image(box->map.mlx,
						"./img/E2.xpm", &box->img.size_img, &box->img.size_img);
		}
		box->map.mapm[box->moves.i][box->moves.j - 1] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i][box->moves.j - 1] == 'E')
	{
		if (box->img.victory_obj == 0)
			exit (0);
	}
	else if (box->map.mapm[box->moves.i][box->moves.j - 1] == 'N')
		exit (0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

void	move_right(t_all *box)
{
	mlx_clear_window(box->map.mlx, box->map.window);
	if (box->map.mapm[box->moves.i][box->moves.j + 1] == '0' ||
		box->map.mapm[box->moves.i][box->moves.j + 1] == 'C')
	{
		if (box->map.mapm[box->moves.i][box->moves.j + 1] == 'C')
		{
			box->img.victory_obj--;
			if (box->img.victory_obj == 0)
				box->img.exit = mlx_xpm_file_to_image(box->map.mlx,
						"./img/E2.xpm", &box->img.size_img, &box->img.size_img);
		}
		box->map.mapm[box->moves.i][box->moves.j + 1] = 'P';
		box->map.mapm[box->moves.i][box->moves.j] = '0';
	}
	else if (box->map.mapm[box->moves.i][box->moves.j + 1] == 'E')
	{
		if (box->img.victory_obj == 0)
			exit (0);
	}
	else if (box->map.mapm[box->moves.i][box->moves.j + 1] == 'N')
		exit (0);
	player_position(box);
	remaining_collect(box);
	print_counter(box);
	put_img01(box);
}

int	key_input(int k, t_all *box)
{
	if (k == 13 || k == 126)
	{
		move_up(box);
	}
	else if (k == 1 || k == 125)
	{
		move_down(box);
	}
	else if (k == 2 || k == 124)
	{
		box->img.current_player = box->img.player_r;
		move_right(box);
	}
	else if (k == 0 || k == 123)
	{	
		box->img.current_player = box->img.player_l;
		move_left(box);
	}
	else if (k == 53)
	{
		free_memory(box);
	}
	return (0);
}
