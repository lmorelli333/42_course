/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:54:48 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 21:16:43 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	compare_moves(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(stack_a);
	if (ft_strcmp(str, "sb\n") == 0)
		swap(stack_b);
	if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	if (ft_strcmp(str, "pa\n") == 0)
		push(stack_b, stack_a);
	if (ft_strcmp(str, "pb\n") == 0)
		push(stack_a, stack_b);
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	if (ft_strcmp(str, "rra\n") == 0)
		rev_rotate(stack_a);
	if (ft_strcmp(str, "rrb\n") == 0)
		rev_rotate(stack_b);
	if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
}

static void	checker_body(char *str, t_list **stack_a, t_list **stack_b)
{
	while (str)
	{
		compare_moves(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(*stack_a))
		ft_putstr("OK\n");
	else if (!is_sorted(*stack_a))
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	int		flag;
	char	*str;

	flag = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		flag = 1;
		av = ft_split(av[1], ' ');
	}
	if (!check_av(av, flag))
		free_av(av, flag);
	stack_a = insert_values(ac, av, flag);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	replace_numbers(stack_a, size);
	str = get_next_line(0);
	checker_body(str, &stack_a, &stack_b);
	free_stack(&stack_a, &flag, av);
	return (0);
}
