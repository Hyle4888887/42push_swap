/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:36:35 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 16:51:27 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void reduc_sort_3(t_tlist **stack_a, int min, t_tlist *head)
{
    if (head->next->index == min)
        ra(stack_a);
    else
    {
        sa(stack_a);
        rra(stack_a);
    }
}

static void sort_3(t_tlist **stack_a)
{
    t_tlist *head;
    int     min;
    int     next_min;

    head = *stack_a;
    min = get_min(stack_a, -1);
    next_min = get_min(stack_a, min);
    if (is_sorted(stack_a))
        return ;
    if (head->index == min && head->next->index != next_min)
    {
        ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
    else if (head->index == next_min)
    {
        if (head->next->index == min)
            sa(stack_a);
        else
            rra(stack_a);
    }
    else
        reduc_sort_3(stack_a, min, head);
}

static void sort_4(t_tlist **stack_a, t_tlist **stack_b)
{
    int distance;
    
    if (is_sorted(stack_a))
        return ;
    distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1)
        ra(stack_a);
    else if (distance == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (distance == 3)
        rra(stack_a);
    if (is_sorted(stack_a))
        return;
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

static void sort_5(t_tlist **stack_a, t_tlist **stack_b)
{
    int distance;

    distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1)
        ra(stack_a);
    else if (distance == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (distance == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if (distance == 4)
        rra(stack_a);
    if (is_sorted(stack_a))
        return ;
    pb(stack_a, stack_b);
    sort_4(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void    simple_sort(t_tlist **stack_a, t_tlist **stack_b)
{
    int size;

    if (is_sorted(stack_a) || ft_lsttsize(*stack_a) <= 1)
        return ;
    size = ft_lsttsize(*stack_a);
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_3(stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}