/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:25:12 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/17 15:44:34 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index(t_list *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	easy_sort(t_list **stack)
{
	int		max;

	if (is_sorted(*stack))
		return ;
	max = max_index(*stack);
	if ((*stack)->index == max)
		ra(stack);
	else if ((*stack)->next->index == max)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort(t_list	**stack_a, t_list **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		easy_sort(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		hard_sort(stack_a, stack_b);
}
