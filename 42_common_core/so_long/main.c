/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:59:06 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/11 01:31:07 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_all *box)
{	
	int	i;

	i = 0;
	while (box->map.mapm[i])
	{
		free(box->map.mapm[i]);
		i++;
	}
	free(box->map.mapm);
	mlx_destroy_image(box->map.mlx, box->img.player_r);
	mlx_destroy_image(box->map.mlx, box->img.player_l);
	mlx_destroy_image(box->map.mlx, box->img.enemy);
	mlx_destroy_image(box->map.mlx, box->img.coll);
	mlx_destroy_image(box->map.mlx, box->img.wall);
	mlx_destroy_image(box->map.mlx, box->img.exit);
	mlx_destroy_image(box->map.mlx, box->img.back);
	free(box->map.mlx);
	exit(0);
}

static void	utils(t_all *box)
{
	box->img.size_img = 64;
	box->img.victory_obj = 0;
	box->moves.counter = 1;
	box->img.patrol_flag = 1;
}

void	print_counter(t_all *box)
{
	box->img.display_moves = ft_itoa(box->moves.counter);
	mlx_string_put(box->map.mlx, box->map.window, 20, 30, 0xFFFFFF, "MOVES : ");
	mlx_string_put(box->map.mlx, box->map.window, 100, 30, 0xFFFFFF,
		box->img.display_moves);
	box->moves.counter++;
	free(box->img.display_moves);
}

int	main(int ac, char **av)
{
	t_all	box;

	if (ac != 2)
	{
		ft_printf("Error\n%s\n", strerror(EINVAL));
		exit (1);
	}
	utils(&box);
	check_av(av[1]);
	read_map(av[1], &box);
	player_position(&box);
	check_rect(&box);
	check_letters01(&box);
	check_letters02(&box);
	check_wall(&box);
	free(box.map.mapv);
	window(&box);
	take_img(&box);
	box.img.current_player = box.img.player_r;
	put_img01(&box);
	mlx_key_hook(box.map.window, key_input, &box);
	mlx_loop_hook(box.map.mlx, enemy_patrol, &box);
	mlx_loop(box.map.mlx);
	free_memory(&box);
	return (0);
}
