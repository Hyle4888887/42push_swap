/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:34:18 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 15:51:24 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	push(t_stack_node **to, t_stack_node **from)
{
	;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
