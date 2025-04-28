/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:37:11 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 16:48:43 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_slist
{
    int             value;
    int             index;
    long long       result;
    int             sign;
    struct s_slist  *next;
}   t_tlist;

//void    print_list(t_tlist *head);

int     get_min(t_tlist **stack, int val);
int     get_distance(t_tlist **stack, int index);

// Utils
void    ft_check_args(int argc, char **argv);
void    free_stack(t_tlist **stack);
void    index_stack(t_tlist **stack);
int     ft_lsttsize(t_tlist *stack);
t_tlist *ft_lsttlast(t_tlist *stack);
t_tlist *ft_lsttnew(int value);
void    ft_lsttadd_back(t_tlist **stack, t_tlist *new);

// Sort
void    simple_sort(t_tlist **stack_a, t_tlist **stack_b);
void    radix_sort(t_tlist **stack_a, t_tlist **stack_b);
bool    is_sorted(t_tlist **stack);

// Commands
int     pa(t_tlist **stack_a, t_tlist **stack_b);
int     pb(t_tlist **stack_a, t_tlist **stack_b);
int     sa(t_tlist **stack_a);
int     sb(t_tlist **stack_b);
int     ss(t_tlist **stack_a, t_tlist **stack_b);
int     ra(t_tlist **stack_a);
int     rb(t_tlist **stack_b);
int     rr(t_tlist **stack_a, t_tlist **stack_b);
int     rra(t_tlist **stack_a);
int     rrb(t_tlist **stack_b);
int     rrr(t_tlist **stack_a, t_tlist **stack_b);

#endif
