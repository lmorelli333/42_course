/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:44:56 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/17 16:20:33 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_and_exit(t_list **stack_a, int flag, char **av)
{
	free_stack(stack_a, &flag, av);
	ft_putstr("Error\n");
	exit (1);
}

t_list	*inizialize_stack(int nb)
{
	t_list	*stack_a;

	stack_a = malloc(sizeof * stack_a);
	if (!stack_a)
		return (NULL);
	stack_a->nb = nb;
	stack_a->index = 0;
	stack_a->pos = -1;
	stack_a->ideal_position = -1;
	stack_a->moves_a = -1;
	stack_a->moves_b = -1;
	stack_a->next = NULL;
	return (stack_a);
}

static int	matrix_size(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

t_list	*insert_values02(char **av, int flag)
{
	t_list		*stack_a;
	long int	nb;
	int			i;
	int			size;

	stack_a = NULL;
	nb = 0;
	i = 0;
	size = matrix_size(av);
	while (i < size)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_and_exit(&stack_a, flag, av);
		if ((i == 1 && flag == 0) || (i == 0 && flag == 1))
			stack_a = inizialize_stack((int)nb);
		else
			ft_lstadd_back(&stack_a, inizialize_stack((int)nb));
		i++;
	}
	return (stack_a);
}

t_list	*insert_values(int ac, char **av, int flag)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	if (flag == 1)
		stack_a = insert_values02(av, flag);
	else
	{
		i = 1;
		while (i < ac)
		{
			nb = ft_atoi(av[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				free_and_exit(&stack_a, flag, av);
			if ((i == 1 && flag == 0) || (i == 0 && flag == 1))
				stack_a = inizialize_stack((int)nb);
			else
				ft_lstadd_back(&stack_a, inizialize_stack((int)nb));
			i++;
		}
	}
	return (stack_a);
}
