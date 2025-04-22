/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:38:07 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/19 15:16:22 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match;

	while (b)
	{
		best_match = (find_max(a))->nbr;
		target_node = (find_max(a));
		current_a = a;
		while (current_a)
		{
			if (b->nbr < current_a->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		b->target_node = target_node;
		b = b->next;
	}
}

static void	cost_analysis_b(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_middle))
			b->push_cost = len_b - (b->index); 
		
		if (b->target_node->above_middle)
			b->push_cost += len_a - (b->target_node->index);
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	if (!b)
		return;
	current_index(a);
	current_index(b);
	set_target_b(a, b);
	cost_analysis_b(a, b);
	set_cheapest(b);
}
