/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:40:24 by khhammou          #+#    #+#             */
/*   Updated: 2026/02/01 00:58:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_flags
{
	t_strategy	strategy;
	int			bench;
	int			num_start;
}	t_flags;

/* Parsing & Validation */
t_flags	parse_flags(int ac, char **av);
int		*parse_numbers(char **av, int start, int *count);
void	fill_numbers(char **av, int start, int *numbers);
int		ft_atoi_safe(char *str, int *error);
int		is_valid_number(char *str);
int		has_duplicates(int *arr, int size);
int		has_spaces(char *str);
int		count_numbers(char **av, int start);
int		check_flag(char *str);

/* Stack Operations */
t_node	*create_node(int value);
void	add_node_back(t_node **head, t_node *new);
t_node	*build_stack(int *numbers, int count);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
// void	rotate_to_top(t_node **stack, int pos, int size);

// /* Sorting Operations */
// void	sa(t_node **a);
// void	sb(t_node **b);
// void	ss(t_node **a, t_node **b);
// void	pa(t_node **a, t_node **b);
// void	pb(t_node **a, t_node **b);
// void	ra(t_node **a);
// void	rb(t_node **b);
// void	rr(t_node **a, t_node **b);
// void	rra(t_node **a);
// void	rrb(t_node **b);
// void	rrr(t_node **a, t_node **b);

// /* Sorting Algorithms */
// void	sort_simple(t_node **a, t_node **b);
// void	sort_medium(t_node **a, t_node **b);
// void	sort_complex(t_node **a, t_node **b);
// void	sort_adaptive(t_node **a, t_node **b, double disorder);

/* Utils */
void	assign_ranks(t_node *stack, int size);
void	sort_array(int *arr, int size);
double	calculate_disorder(t_node *stack);
int		calculate_chunk_size(int size);
int		find_max_position(t_node *stack);
void	free_split(char **split);
void	print_error(void);
int		ft_strcmp(const char *s1, const char *s2);

/* Checker (no print operations) */
void	swap_no_print(t_node **stack);
void	push_no_print(t_node **dest, t_node **src);
void	rotate_no_print(t_node **stack);
void	reverse_rotate_no_print(t_node **stack);
void	execute_operation(char *op, t_node **a, t_node **b);
int		is_sorted(t_node *stack);

/* Benchmark */
// void	print_benchmark(double disorder, t_flags flags);
// void	rotate_to_top_a(t_node **a, int pos, int size);
// void	rotate_to_top_b(t_node **b, int pos, int size);
int		is_sorted(t_node *stack);
// Add these to your function declarations
char    *ft_strjoin_free(char *s1, char *s2);
int     total_ops(char *ops);
int     c_op(char *ops, char *op_name);

// Update all operation functions to take char **ops parameter:
void    sa(t_node **a, char **ops);
void    sb(t_node **b, char **ops);
void    ss(t_node **a, t_node **b, char **ops);
void    pa(t_node **a, t_node **b, char **ops);
void    pb(t_node **a, t_node **b, char **ops);
void    ra(t_node **a, char **ops);
void    rb(t_node **b, char **ops);
void    rr(t_node **a, t_node **b, char **ops);
void    rra(t_node **a, char **ops);
void    rrb(t_node **b, char **ops);
void    rrr(t_node **a, t_node **b, char **ops);

// Update sorting functions:
void    sort_simple(t_node **a, t_node **b, char **ops);
void    sort_medium(t_node **a, t_node **b, char **ops);
void    sort_complex(t_node **a, t_node **b, char **ops);
void    sort_adaptive(t_node **a, t_node **b, double disorder, char **ops);
// Update these function signatures:
void    sort_simple(t_node **a, t_node **b, char **ops);
void    sort_medium(t_node **a, t_node **b, char **ops);
void    sort_complex(t_node **a, t_node **b, char **ops);
void    sort_adaptive(t_node **a, t_node **b, double disorder, char **ops);

void    rotate_to_top(t_node **stack, int pos, int size, char **ops);
void    rotate_to_top_a(t_node **a, int pos, int size, char **ops);
void    rotate_to_top_b(t_node **b, int pos, int size, char **ops);

// Add these new utility functions:
char    *ft_strjoin_free(char *s1, char *s2);
int     total_ops(char *ops);
int     c_op(char *ops, char *op_name);

// Update benchmark function:
void    print_benchmark(double disorder, t_flags flags, char *ops);
char    *ft_strjoin_free(char *s1, char *s2);
int     total_ops(char *ops);
int     c_op(char *ops, char *op_name);


#endif