/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:33:53 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/16 15:22:07 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;
	
	print_list(*stack, "Before rotate");
	first_node = *stack;
	last_node = find_last(*stack);
	first_node->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	*stack = last_node;	
	current_index(*stack);
	print_list(*stack, "After rotate");
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	int i = 0;
	while ((*b != cheapest_node->target_node || *a != cheapest_node) && (i++) < 5)
	{
		if (*b == cheapest_node)
			rra(a);
		else if (*a == cheapest_node->target_node)
			rrb(b);
		else
			rrr(a, b);
	}
	current_index(*a);
	current_index(*b);
}
