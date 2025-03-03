/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:06:57 by mpoirier          #+#    #+#             */
/*   Updated: 2025/03/04 16:18:37 by mpoirier         ###   ########.fr       */
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
	print_list(a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	printf("end of main: \n");
	print_list(a);
	free_stack(&a);
	return (0);
}

void print_list(t_stack_node *stack)
{
	while (stack != NULL) {
		printf("Node numéro %i: %p ; data : %i\n", stack->index, stack, stack->nbr); 
		stack = stack->next; }
	return ;
}

