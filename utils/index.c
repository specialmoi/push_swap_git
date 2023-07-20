/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:51:34 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/13 20:49:21 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	t_stack	*get_next_min(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*min;
	int		min_exists;

	head = *stack_a;
	min = NULL;
	min_exists = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!min_exists || head->data < min->data))
			{
				min = head;
				min_exists = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_stack **stack_a)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack_a);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack_a);
	}
}
