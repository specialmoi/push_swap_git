/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:49:33 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/13 21:22:18 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "./libft/libft.h"

typedef struct s_stack
{
	long			data;
	int				index;
	struct s_stack	*next;
}	t_stack;

//Utils
void	ft_error(char *msg);
void	ft_free(char **str);
void	free_stack(t_stack **stack);

int		ft_isnum(char *num);
void	ft_create_args(int argc, char **argv);
void	ft_check_args(int argc, char **args, int i);

void	index_stack(t_stack **stack_a);

int		get_distance(t_stack **stack_a, int index);
int		ft_is_sorted(t_stack **stack_a);

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstdelone(t_stack *lst, void (*del)(long));
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(long content);
int		ft_lstsize(t_stack *stack);
void	print_stack(t_stack *head);

//simple
int		get_min(t_stack **stack, int val);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

//instructions
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_a);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

//radix
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		get_max_bits(t_stack **stack);

#endif
