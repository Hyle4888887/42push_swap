/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_something.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:03:25 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 18:19:30 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *get_min(t_stack_node *stack, int val)
{
    t_stack_node    *min;
    
    min->value = stack->value;
    while (stack)
    {
        if ((stack->value < min->value) && (stack->final_index != val))
            min = stack;
        stack = stack->next;
    }
    return (min)
}

void	get_min_on_top(t_stack_node **a)
{
    t_stack_node    *min;

    min = get_min(*a, -1);
	while ((*a) != min)
	{
		if (min->above_middle)
			ra(a);
		else
			rra(a);
	}
}

int get_distance(t_stack_node **stack, int index)
{
    t_stack_node *head;
    int     distance;

    distance = 0;
    head = *stack;
    while (head)
    {
        if (head->index == index)
            break ;
        distance++;
        head = head->next;
    }
    return (distance);
}
