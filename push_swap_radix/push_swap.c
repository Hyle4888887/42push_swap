/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:06 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 16:27:00 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	initstack(t_tlist **stack, int argc, char **argv)
{
    t_tlist *new;
    char    **args;
    int     i;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
        new = ft_lsttnew(ft_atoi(args[i]));
        ft_lsttadd_back(stack, new);
        i++;
    }
    index_stack(stack);
    if (argc == 2)
        ft_free_split(args);
}

static void sort_stack(t_tlist **stack_a, t_tlist **stack_b)
{
    if (ft_lsttsize(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_tlist **stack_a;
    t_tlist **stack_b;

    if (argc < 2)
        return (-1);
    ft_check_args(argc, argv);
    stack_a = (t_tlist **)malloc(sizeof(t_tlist));
    stack_b = (t_tlist **)malloc(sizeof(t_tlist));
    *stack_a = NULL;
    *stack_b = NULL;
    initstack(stack_a, argc, argv);
    if (is_sorted(stack_a))
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}

/*
void    print_list(t_tlist *head)
{
    t_tlist *tmp;

    tmp = head;
    while (tmp != NULL)
    {
        ft_putnbr_fd(tmp->value, 1);
        ft_putendl_fd("", 1);
        tmp = tmp->next;
    }
}
*/