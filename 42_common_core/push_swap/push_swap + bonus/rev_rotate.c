/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:23:24 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 16:31:52 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstsecondlast(t_list *head)
{
	while (head->next->next)
		head = head->next;
	return (head);
}

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(*stack);
	second_last = ft_lstsecondlast(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	second_last->next = NULL;
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (flag == 1)
		ft_putstr("rrr\n");
}
