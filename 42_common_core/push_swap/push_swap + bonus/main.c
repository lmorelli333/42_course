/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:56:53 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 19:39:27 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!check_av(av, flag))
		free_av(av, flag);
	stack_a = insert_values(ac, av, flag);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	replace_numbers(stack_a, size + 1);
	sort(&stack_a, &stack_b, size);
	free_stack(&stack_a, &flag, av);
	return (0);
}
