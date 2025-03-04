/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:34:18 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/04 16:24:49 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;
	
	if (!(*b))
		return ;
	node = (*b);
	(*b) = (*b)->next;
	(*b)->prev = NULL;
	node->next = (*a);
	(*a) = node;
	current_index(*a);
	current_index(*b);
	printf("Stack a: \n");
	print_list(*a);
	printf("Stack B \n");
	print_list(*b);
	write(1, "pb\n", 3);
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
	current_index(*b);
	printf("Stack a: \n");
	print_list(*a);
	printf("Stack B \n");
	print_list(*b);
	write(1, "pa\n", 3);
}
