/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:54:41 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/18 18:54:41 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int  get_max_bits(t_tlist **stack)
{
    t_tlist *head;
    int     max;
    int     max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(t_tlist **stack_a, t_tlist **stack_b)
{
    t_tlist *head_a;
    int     i;
    int     j;
    int     size;
    int     max_bits;

    i = 0;
    head_a = *stack_a;
    size = ft_lsttsize(head_a);
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            head_a = *stack_a;
            if (((head_a->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (ft_lsttsize(*stack_b) != 0)
            pa(stack_a, stack_b);
        i++;
    }
}