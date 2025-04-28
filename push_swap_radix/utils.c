/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:52:01 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 16:29:11 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

bool    is_sorted(t_tlist **stack)
{
    t_tlist *head;

    head = *stack;
    while (head && head->next)
    {
        if (head->value > head->next->value)
            return (false);
        head = head->next;
    }
    return (true);
}

static t_tlist *get_next_min(t_tlist **stack)
{
    t_tlist *head;
    t_tlist *min;
    bool    has_min;

    min = NULL;
    has_min = false;
    head = *stack;
    if (head)
    {
        while (head)
        {
            if ((head->index == -1) && (!has_min || head->value < min->value))
            {
                min = head;
                has_min = true;
            }
            head = head->next;
        }
    }
    return (min);
}

void    index_stack(t_tlist **stack)
{
    t_tlist *head;
    int     index;

    index = 0;
    head = get_next_min(stack);
    while (head)
    {
        head->index = index++;
        head = get_next_min(stack);
    }
}

void    free_stack(t_tlist **stack)
{
    t_tlist *head;
    t_tlist *tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(stack);
}

void    make_top(t_tlist **stack, int distance)
{
    t_tlist *head;
    int     tmp;
    int     size;

    if (distance == 0)
        return ;
    head = *stack;
    size = ft_lsttsize(head);
    tmp = size - distance;
    if (distance <= (size / 2))
    {
        while (distance-- > 0)
            ra(stack);
    }
    else
    {
        while (tmp-- > 0)
            rra(stack);
    }
}