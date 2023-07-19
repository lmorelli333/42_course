/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:30:18 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/17 15:12:47 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remove_sign(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	fastest_nb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		fastest;
	int		moves_a;
	int		moves_b;

	tmp = *stack_b;
	fastest = INT_MAX;
	while (tmp)
	{
		if (remove_sign(tmp->moves_a) + remove_sign(tmp->moves_b)
			< remove_sign(fastest))
		{
			fastest = remove_sign(tmp->moves_b) + remove_sign(tmp->moves_a);
			moves_a = tmp->moves_a;
			moves_b = tmp->moves_b;
		}
		tmp = tmp->next;
	}
	start_moving(stack_a, stack_b, moves_a, moves_b);
}

void	moves_calculator(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(tmp_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->moves_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->moves_b = (size_b - tmp_b->pos) * -1;
		tmp_b->moves_a = tmp_b->ideal_position;
		if (tmp_b->ideal_position > size_a / 2)
			tmp_b->moves_a = (size_a - tmp_b->ideal_position) * -1;
		tmp_b = tmp_b->next;
	}
}
