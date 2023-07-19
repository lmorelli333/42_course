/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:19:11 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 16:29:43 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_a_b(t_list **a, t_list **b, int *moves_a, int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		(*moves_a)++;
		(*moves_b)++;
		rrr(a, b, 1);
	}
}

static void	rotate_a_b(t_list **a, t_list **b, int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		(*moves_a)--;
		(*moves_b)--;
		rr(a, b, 1);
	}
}

static void	rotate_a(t_list **a, int *moves)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			ra(a);
			(*moves)--;
		}
		else if (*moves < 0)
		{
			rra(a);
			(*moves)++;
		}
	}
}

static void	rotate_b(t_list **b, int *moves)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			rb(b);
			(*moves)--;
		}
		else if (*moves < 0)
		{
			rrb(b);
			(*moves)++;
		}
	}
}

void	start_moving(t_list **a, t_list **b, int moves_a, int moves_b)
{
	if (moves_a > 0 && moves_b > 0)
		rotate_a_b(a, b, &moves_a, &moves_b);
	else if (moves_a < 0 && moves_b < 0)
		rev_rotate_a_b(a, b, &moves_a, &moves_b);
	rotate_a(a, &moves_a);
	rotate_b(b, &moves_b);
	pa(a, b);
}
