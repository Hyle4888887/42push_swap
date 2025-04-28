/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:49:35 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/05 11:47:39 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node *first;
    	t_stack_node *second;

    	if (!stack || !*stack || !(*stack)->next)
        	return;

    first  = *stack;          /* ancien premier  */
    second = first->next;     /* ancien second   */

    /* on détache ‘first’ du reste de la liste */
    first->next = second->next;
    if (first->next)              /* si un troisième nœud existe      */
        first->next->prev = first;/*     on met à jour son prev       */

    /* on place ‘second’ devant ‘first’ */
    second->prev = NULL;
    second->next = first;
    first->prev  = second;

    /* nouvelle tête de pile */
    *stack = second;
}

/*{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	first = (*stack);
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	(*stack) = second;
	current_index(*stack);
}*/

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
