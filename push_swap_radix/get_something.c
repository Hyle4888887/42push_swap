/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_something.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:27:34 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 16:29:32 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int get_distance(t_tlist **stack, int index)
{
    t_tlist *head;
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

int get_min(t_tlist **stack, int val)
{
    t_tlist *head;
    int     min;

    head = *stack;
    min = head->index;
    while (head->next)
    {
        head = head->next;
        if ((head->index < min) && head->index != val)
            min = head->index;
    }
    return (min);
}