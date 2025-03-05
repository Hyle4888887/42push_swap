/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:13:14 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/05 13:14:09 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool error_syntax(const char *s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if (s[i] == ' ')
            continue ;
        else if (s[i] > 47 && s[i] < 58)
            continue ;
        else if (s[i] == '-' && s[i - 1] == ' ' && (s[i+1] > 47 && s[i+1] < 58))
            continue ;
        else
            return (true);
    }
    return (false);
}

bool error_duplicate(t_stack_node *a, int n)
{
    while (a)
    {
        if (a->nbr == n)
            return (true);
        a = a->next;
    }
    return (false);
}

void    free_errors(t_stack_node **a)
{
    t_stack_node *current;
    t_stack_node *next;
    
    current = *a;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    exit(1);
}

void free_stack(t_stack_node **stack) {
    t_stack_node *current;
    t_stack_node *next;
    
    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}