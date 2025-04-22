/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:05:36 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/19 14:01:04 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*first_node;

	if (!*stack || !((*stack)->next))
		return ;
	first_node = (*stack);
	(*stack) = (*stack)->next;
	last_node = find_last(*stack);
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
	current_index(*stack);
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rotate_both(t_stack_node **stack_to, t_stack_node **stack_from,
		t_stack_node *cheapest_node)
{
	while ((*stack_from != cheapest_node && *stack_to != cheapest_node->target_node) &&
			!(*stack_from) && !(*stack_to))
		rr(stack_to, stack_from);
	current_index(*stack_to);
	current_index(*stack_from);
}
