/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:13:14 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/04 11:30:49 by mpoirier         ###   ########.fr       */
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
    *a = find_last(*a);
    while ((*a)->prev)
    {
        (*a) = (*a)->prev;
        free((*a)->next);
    }
    free((*a)->prev);
    free(*a);
    exit(1);
}

void free_stack(t_stack_node **stack) {
    t_stack_node *current;
    t_stack_node *next;
    
    current = *stack;
    printf("stack prev = %p\n", (*stack)->prev);
    while (current != NULL) {
        next = current->next;  // Save the next pointer before freeing
        printf("Freeing : %p\n", current);
        free(current);         // Free the current node
        current = next;        // Move to the next node
    }
}