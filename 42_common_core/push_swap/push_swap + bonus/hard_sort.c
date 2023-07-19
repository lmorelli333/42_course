/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:18:53 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/15 19:39:37 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_push(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;
	int	pushed;

	size = ft_lstsize(*stack_a);
	i = 0;
	pushed = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	final_rotates(t_list **stack_a)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	min_pos = min_idx_pos(stack_a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
}

void	hard_sort(t_list **stack_a, t_list **stack_b)
{
	first_push(stack_a, stack_b);
	easy_sort(stack_a);
	while (*stack_b)
	{
		searching_a_spot(stack_a, stack_b);
		moves_calculator(stack_a, stack_b);
		fastest_nb(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		final_rotates(stack_a);
}
