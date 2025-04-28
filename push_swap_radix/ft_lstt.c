/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:26:43 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/19 19:26:43 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int ft_lsttsize(t_tlist *head)
{
    size_t  i;
    t_tlist *tmp;

    tmp = head;
    i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

t_tlist *ft_lsttnew(int value)
{
    t_tlist *new;

    new = (t_tlist *)malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new->value = value;
    new->index= -1;
    new->next = NULL;
    return (new);
}

t_tlist *ft_lsttlast(t_tlist *head)
{
    t_tlist *tmp;

    tmp = head;
    while (tmp->next)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
            return (tmp);
    }
    return (tmp);
}

void    ft_lsttadd_back(t_tlist **stack, t_tlist *new)
{
    t_tlist *n;

    if (*stack)
    {
        n = ft_lsttlast(*stack);
        n->next = new;
        new->next = NULL;
    }
    else
    {
        *stack = new;
        (*stack)->next = NULL;
    }
}