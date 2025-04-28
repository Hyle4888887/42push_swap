/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:13:43 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 18:14:14 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_contains(int num, char **argv, int i)
{
    while (argv[++i])
    {
        if (ft_atoi(argv[i]) == num)
            return (1);
    }
    return (0);
}

static void    ft_check_args(int argc, char **argv)
{
    int         i;
    char        **args;
    long long   tmp;

    i = -1;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i += 1;
        args = argv;
    }
    while (args[++i])
    {
        tmp = ft_atoll(args[i]);
        if (!ft_str_is((const char *)(args[i]), ft_isdigit))
            ft_error("Error");
        if (ft_contains(tmp, args, i))
            ft_error("Error");
        if (tmp < INT_MIN || tmp > INT_MAX)
            ft_error("Error");
    }
    if (argc == 2)
        ft_free_split(args);
}

static void initstack(t_stack_node **a, int argc, char **argv)
{
    t_stack_node *new;
    char    *args;
    int     i;

    i = -1;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i += 1;
        args = argv;
    }
    while (args[++i])
    {
        new = ft_lstnew(ft_atoi(args[i]));
        ft_lstadd_back(a, new);
    }
    index_stack(a);
    if (argc == 2)
        ft_free_split(args);
}

int main(int argc, char **argv)
{
    t_stack_node    *stack_a;
    t_stack_node    *stack_b;

    if (argc < 2)
        return (-1);
    stack_a = (t_stack_node *)malloc(sizeof(t_stack_node));
    stack_b = (t_stack_node *)malloc(sizeof(t_stack_node));
    stack_a = NULL;
    stack_b = NULL;
    initstack(&stack_a, argc, argv);
    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (0);
    }
    if (ft_lstsize(stack_a) <= 5)
        simple_sort(&stack_a, &stack_b);
    else
        sort_stack(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}

void print_list(t_stack_node *stack, char *name)
{
    int i;

    i = 0;
	if (!stack)
		return ;
	ft_printf("%s :\n", name);	
	while (stack != NULL) {
		ft_printf("Node numéro %i: %p\n", (i++), stack);
		ft_printf("\t value = \t\t%i\n", stack->value);
		ft_printf("\t final_index = \t%p\n", stack->index);
		ft_printf("\t above_middle = %b\n", stack->above_middle);
		ft_printf("\t cheapest = \t%b\n", stack->cheapest);
		ft_printf("\t next = \t%p\n", stack->next);
		ft_printf("\t prev = \t%p\n", stack->prev);
		write(1, "\n", 1);
		stack = stack->next; }
	return ;
}
