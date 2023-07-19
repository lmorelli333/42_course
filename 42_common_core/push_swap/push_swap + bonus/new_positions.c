/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:23:44 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/21 14:37:39 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	min_idx_pos(t_list **stack)
{
	t_list	*tmp;
	int		min_idx;
	int		min_pos;

	tmp = *stack;
	min_idx = INT_MAX;
	assign_position(stack);
	min_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < min_idx)
		{
			min_idx = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

static int	how_to_find_that_spot(t_list **stack_a, int idx_b,
								int target_idx, int ideal_position)
{
	t_list	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > idx_b && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			ideal_position = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (ideal_position);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			ideal_position = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (ideal_position);
}

void	searching_a_spot(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		ideal_position;

	tmp_b = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
	ideal_position = 0;
	while (tmp_b)
	{
		ideal_position = how_to_find_that_spot(stack_a, tmp_b->index,
				INT_MAX, ideal_position);
		tmp_b->ideal_position = ideal_position;
		tmp_b = tmp_b->next;
	}
}
