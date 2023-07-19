/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:00:21 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 17:05:55 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag == 1)
		ft_putstr("ss\n");
}
