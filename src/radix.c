/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:39:24 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/13 21:24:22 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max_index;
	int		max_bits;

	head = *stack;
	max_index = head->index;
	max_bits = 0;
	while (head)
	{
		if (max_index < head->index)
			max_index = head->index;
		head = head->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits++);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		max_bits;
	int		size;
	int		i;
	int		j;

	head_a = *stack_a;
	max_bits = get_max_bits(stack_a);
	size = ft_lstsize(*stack_a);
	i = 0;
	while (max_bits > i)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
