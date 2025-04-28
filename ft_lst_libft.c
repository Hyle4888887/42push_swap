/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:24:39 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 18:20:23 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_node *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	else
		(*lst) = new;
	return ;
}

t_stack_node	*ft_lstnew(int value)
{
	t_stack_node	*res;

	res = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!res)
		return (NULL);
	res->value = value;
	res->final_index = INT_MIN;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	else
		return (NULL);
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node *tail;
	
	if (*lst)
	{
		tail = ft_lstlast(*lst);
		new->prev = tail;
		new->index = (tail->index) + 1;
		tail->next = new;
	}
	else
		*lst = new;
}
