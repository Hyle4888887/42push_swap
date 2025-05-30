/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:05:49 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/19 17:57:19 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	int				len;
	
	cheapest_node = get_cheapest(*a);
	len = stack_len(*a);
	if (cheapest_node != *a && cheapest_node->target_node != *b && len > 1)
	{
		if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
			rotate_both(b, a, cheapest_node);
		else if (!(cheapest_node->above_middle) && !(cheapest_node->target_node->above_middle))
			rev_rotate_both(b, a, cheapest_node);
	}
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(a, b);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	int				len;

	cheapest_node = get_cheapest(*b);
	len = stack_len(*b);
	if (cheapest_node != *b && cheapest_node->target_node != *a && len > 1)
	{
		if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_middle) && !(cheapest_node->target_node->above_middle))
			rev_rotate_both(a, b, cheapest_node);
	}
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, cheapest_node->target_node, 'a');
	push_a(a, b);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_middle)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	int i = 0;
	if (!stack_sorted(*a))
		min_on_top(a);
	if ((len--) > 3 && !stack_sorted(*a))
		push_b(a, b);
	if ((len--) > 3 && !stack_sorted(*a))
		push_b(a, b);
	while ((len--) > 3 && !stack_sorted(*a) && (i++) < 10)
	{
		init_nodes_a(*a, *b);
		init_nodes_b(*a, *b);
		move_a_to_b(a, b);
	}
	if (i == 10) {
		free_stack(a);
		free_stack(b);
		return ; }
	init_nodes_a(*a, *b);
	init_nodes_b(*a, *b);
	if (stack_sorted(*a) == false) {
		printf("HAHA\n");
		sort_three(a); }
	i = 0;
	while (*b &&(i++) < 10)
	{
		printf("bonjour\n");
		init_nodes_a(*a, *b);
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	if (i == 10) {
		free_stack(a);
		free_stack(b);
		return ; }
	current_index(*a);
	min_on_top(a);
}
