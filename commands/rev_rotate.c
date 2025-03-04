/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:33:53 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/04 14:19:45 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	int				i;

	first_node = find_last(*stack);
	i = stack_len(*stack);
	first_node->next = (*stack);
	first_node->prev = NULL;
	printf("index last_node: %i \n", first_node->index);
	while ((--i) > 0)
	{
		printf("data node: %i\nindex: %i\n", (*stack)->nbr, i);
		(*stack) = (*stack)->next;
	}
	(*stack)->next = NULL;
	(*stack) = first_node;
	printf("rev_rotate: \n");
	print_list(*stack);
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
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
