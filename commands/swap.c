/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:49:35 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/04 11:32:05 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*node;

	node = (*stack)->next;
	node->next = (*stack);
	node->prev = NULL;
	node->next->next = (*stack)->next->next;
	node->next->prev = (*stack)->next;
	node->index = 0;
	node->next->index = 1;
	(*stack) = node;
	printf("Node %i: %p ; data : %i\n", node->index,node, node->nbr);
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
