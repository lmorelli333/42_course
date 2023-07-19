/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:06:53 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 21:08:47 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	free_av(char **av, int flag)
{
	int	i;

	write(2, "Error\n", 6);
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
