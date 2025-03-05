/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:34:18 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/05 14:10:14 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rra(stack);
		}
	}
}

void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;
	
	if (!(*b))
		return ;
	node = (*b);
	(*b) = (*b)->next;
	if ((*b))
		(*b)->prev = NULL;
	node->next = (*a);
	(*a) = node;
	current_index(*a);
	current_index(*b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;
	
	if (!(*a))
		return ;
	node = (*a);
	(*a) = (*a)->next;
	(*a)->prev = NULL;
	node->next = (*b);
	(*b) = node;
	current_index(*a);
	current_index(*b);;
	write(1, "pb\n", 3);
}
