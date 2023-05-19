/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:01:05 by lmorelli          #+#    #+#             */
/*   Updated: 2023/05/11 01:37:03 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_map
{
	void	*mlx;
	void	*window;
	char	**mapm;
	char	*mapv;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_moves
{
	int	counter;
	int	i;
	int	j;
	int	x;
	int	y;
	int	patrol;
}	t_moves;

typedef struct s_image
{
	int		size_img;
	void	*current_player;
	void	*player_r;
	void	*player_l;
	void	*enemy;
	void	*coll;
	void	*back;
	void	*wall;
	void	*exit;
	int		victory_obj;
	char	*display_moves;
	int		patrol_flag;
}	t_image;

typedef struct s_all
{
	t_moves	moves;
	t_map	map;
	t_image	img;
}	t_all;

int		main(int ac, char **av);
void	check_av(char *av);
void	check_wall(t_all *box);
void	check_letters01(t_all *box);
void	check_letters02(t_all *box);
void	check_rect(t_all *box);
void	read_map(char *av, t_all *box);
void	move_up_enemy(t_all *box);
void	move_down_enemy(t_all *box);
void	move_left_enemy(t_all *box);
void	move_right_enemy(t_all *box);
void	put_img01(t_all *box);
void	put_img02(int i, int j, t_all *box);
void	take_img(t_all *box);
void	window(t_all *box);
int		key_input(int k, t_all *box);
void	free_memory(t_all *box);
void	player_position(t_all *box);
void	remaining_collect(t_all *box);
void	print_counter(t_all *box);
int		enemy_patrol(t_all *box);
void	put_anim(t_all *box);

#endif
