/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:05:49 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/05 14:52:01 by mpoirier         ###   ########.fr       */
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

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(a, b);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, (*b)->target_node, 'a');
	push_a(a, b);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	int i = 0;
	if ((len_a--) > 3 && !stack_sorted(*a))
		push_b(a, b);
	//write(1, "L1\n", 3); print_list(*a, "A"); print_list(*b, "B");
	if ((len_a--) > 3 && !stack_sorted(*a))
		push_b(a, b);
	//write(1, "L2\n", 3); print_list(*a, "A"); print_list(*b, "B");
	while ((len_a--) > 3 && !stack_sorted(*a) && (i++) < 10)
	{
		init_nodes_a(*a, *b);
		init_nodes_b(*a, *b);
		move_a_to_b(a, b);
	}
	if (i == 10) {
		free_stack(a);
		free_stack(b);
		return ; }
	//write(1, "L3\n", 3); print_list(*a, "A"); print_list(*b, "B");
	init_nodes_a(*a, *b);
	init_nodes_b(*a, *b);
	//write(1, "L4\n", 3); print_list(*a, "A"); print_list(*b, "B");
	if (!stack_sorted(*a))
		sort_three(a);
	//write(1, "L5\n", 3); print_list(*a, "A"); print_list(*b, "B");
	i = 0;
	while (*b && (i++) < 10)
	{
		init_nodes_a(*a, *b);
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	if (i == 10) {
		free_stack(a);
		free_stack(b);
		return ; }
	//write(1, "L6\n", 3); print_list(*a, "A"); print_list(*b, "B");
	current_index(*a);
	//write(1, "L7\n", 3); print_list(*a, "A"); print_list(*b, "B");
	min_on_top(a);
	//write(1, "L8\n", 3); print_list(*a, "A"); print_list(*b, "B");
}
