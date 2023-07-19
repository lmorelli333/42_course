/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:26:38 by lmorelli          #+#    #+#             */
/*   Updated: 2023/06/26 19:41:36 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	int				nb;
	int				index;
	int				pos;
	int				ideal_position;
	int				moves_a;
	int				moves_b;
	struct s_list	*next;
}		t_list;

void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b, int flag);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b, int flag);
void		rrr(t_list **stack_a, t_list **stack_b, int flag);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		push(t_list **src, t_list **dest);
void		swap(t_list **stack);
void		rotate(t_list **stack);
void		rev_rotate(t_list **stack);
int			is_sorted(t_list *stack);
void		easy_sort(t_list **stack);
void		hard_sort(t_list **stack_a, t_list **stack_b);
void		free_stack(t_list **stack, int *flag, char **av);
void		replace_numbers(t_list *stack_a, int stack_size);
t_list		*insert_values(int ac, char **av, int flag);
t_list		*inizialize_stack(int nb);
void		searching_a_spot(t_list **a, t_list **b);
int			min_idx_pos(t_list **stack);
void		moves_calculator(t_list **stack_a, t_list **stack_b);
void		fastest_nb(t_list **stack_a, t_list **stack_b);
void		start_moving(t_list **a, t_list **b, int moves_a, int moves_b);
int			check_av(char **av, int flag);
int			remove_sign(int x);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
int			ft_isdigit(int c);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(const char *s, char c);
t_list		*insert_values02(char **av, int flag);
void		sort(t_list	**stack_a, t_list **stack_b, int size);
void		ft_lstadd_back(t_list **lst, t_list *new);
long int	ft_atoi(const char *str);
int			ft_putstr(char *str);
size_t		ft_strlen(const char *str);
void		free_av(char **av, int flag);

#endif