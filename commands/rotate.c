/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:05:36 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/14 15:48:14 by mpoirier         ###   ########.fr       */
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

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	print_list(*a, "A") ; print_list(*b, "B");
	printf("rr cheapest_node = %p\n", cheapest_node);
	printf("rr cheapest_node->target = %p\n", cheapest_node->target_node);
	int i = 0;
	while ((*b != cheapest_node || *a != cheapest_node->target_node) && (i++) < 10)
	{
		if (*b == cheapest_node)
			ra(a);
		else if (*a == cheapest_node->target_node)
			rb(b);
		else
			rr(a, b);
	}
	current_index(*a);
	current_index(*b);
}
