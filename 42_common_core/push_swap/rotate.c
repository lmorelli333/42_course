/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:24:25 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/17 16:21:49 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
