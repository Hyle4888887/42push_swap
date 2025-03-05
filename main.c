/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:06:57 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/05 14:39:09 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split((const char *)argv[1], ' ');
	init_stack_a(&a, argv);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}

void print_list(t_stack_node *stack, char *name)
{
	printf("%s :\n", name);	
	while (stack != NULL) {
		printf("Node numéro %i: %p\n", stack->index, stack);
		printf("\t nbr = \t\t%i\n", stack->nbr);
		printf("\t push_cost = \t%i\n", stack->push_cost);
		printf("\t above_median = %s\n", (stack->above_median) ? "true" : "false");
		printf("\t cheapest = \t%s\n", (stack->cheapest) ? "true" : "false"); 
		printf("\t target_node = \t%p\n", stack->target_node);
		printf("\t next = \t%p\n", stack->next);
		printf("\t prev = \t%p\n", stack->prev);
		write(1, "\n", 1);
		stack = stack->next; }
	return ;
}

