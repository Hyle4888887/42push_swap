/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:39 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:42 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_mean;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					print_list(t_stack_node *stack, char *name);

// Libft
int						ft_isdigit(int c);
char					**ft_split(char const *s, char c);
size_t					ft_strlen(const char *str);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);

// Handle errors
bool					error_syntax(const char *s);
bool					error_duplicate(t_stack_node *a, int n);
void					free_errors(t_stack_node **a);

// Stack initiation
void					init_stack_a(t_stack_node **a, char **argv);

// Nodes initiations
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);

// Stack utils
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
void					free_stack(t_stack_node **stack);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);

// Commandes
void					push_a(t_stack_node **a, t_stack_node **b);
void					push_b(t_stack_node **a, t_stack_node **b);
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

// Algorithms
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
