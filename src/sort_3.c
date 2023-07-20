/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:21:15 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/13 21:22:48 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3_cont(int min, int next_min, t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	if (head->index == min && head->next->index != next_min)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == next_min)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	sort_3(t_stack **stack_a)
{
	int		min;
	int		next_min;

	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (ft_is_sorted(stack_a))
		return ;
	sort_3_cont(min, next_min, stack_a);
}
