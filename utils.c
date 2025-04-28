/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:18 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 18:20:33 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_sorted(t_stack_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

void    index_stack(t_stack_node **stack)
{
    t_stack_node    *head;
    int             index;
    int             size;
    int             i;

    size = ft_lstsize(*stack);
    index = -1;
    head = get_min(*stack, -1);
    while (head)
    {
        i = head->index;
        if (i < (size / 2))
            head->above_middle = true;
        else
            head->above_middle = false;
        head->final_index = (++index);
        head = get_min(stack, index);
    }
}
