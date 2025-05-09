/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:37:25 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/19 14:33:22 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi(const char *s)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		r = r * 10 + (*s++ - '0');
	return (r * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
	}
	current_index(*a);
}

static int	get_middle(t_stack_node *stack) // mean == moyenne en anglais
{
	long	i;
	
	i = 0;
	while (stack && stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return ((int)(i / 2));
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = get_middle(stack);
	while (stack && stack != NULL)
	{
		stack->index = i;
		if (stack->index <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}