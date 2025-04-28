/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:28:28 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 17:21:47 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void    sort_4(t_stack_node **a, t_stack_node **b)
{
    if (is_sorted(*a))
        return ;
    get_min_on_top(a);
    if (is_sorted(*a))
        return ;
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

void    sort_5(t_stack_node **a, t_stack_node **b)
{
    if (is_sorted(*a))
        return ;
    get_min_on_top(a);
    if (is_sorted(*a))
        return ;
    pb(a, b);
    sort_4(a, b);
    pa(a, b);
}

void	simple_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(*a) || size <= 1)
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		sort_stack(a, b);
}