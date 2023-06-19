/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:53 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/17 16:18:39 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_numbers(t_list *stack_a, int size)
{
	t_list	*tmp;
	t_list	*max;
	int		value;

	while (--size > 0)
	{
		tmp = stack_a;
		value = INT_MIN;
		max = NULL;
		while (tmp)
		{
			if (tmp->nb == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->nb > value && tmp->index == 0)
			{
				value = tmp->nb;
				max = tmp;
			}
			tmp = tmp->next;
		}
		if (max != NULL)
			max->index = size;
	}
}

static void	free_av(char **av, int flag)
{
	int	i;

	ft_putstr("Error\n");
	i = -1;
	if (flag == 1)
	{
		while (av[++i])
			free(av[i]);
		free(av);
	}
	exit (1);
}

void	free_stack(t_list **stack, int *flag, char **av)
{
	t_list	*tmp;
	int		i;

	i = -1;
	if (*flag == 1)
	{
		while (av[++i])
			free(av[i]);
		free(av);
		*flag = 0;
	}
	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	int		flag;

	flag = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		flag = 1;
		av = ft_split(av[1], ' ');
	}
	if (!check_av(av))
		free_av(av, flag);
	stack_a = insert_values(ac, av, flag);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	replace_numbers(stack_a, size + 1);
	sort(&stack_a, &stack_b, size);
	free_stack(&stack_a, &flag, av);
	return (0);
}
