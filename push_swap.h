/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:40:24 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:09:16 by khhammou         ###   ########.fr       */
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

t_flags	parse_flags(int argc, char **argv);
void	print_error(void);
int		ft_strcmp(const char *s1, const char *s2);
int		*parse_numbers(char **argv, int start, int *count);
int		is_valid_number(char *str);
int		has_duplicates(int *arr, int size);
t_node	*create_node(int value);
void	add_node_back(t_node **head, t_node *new);
t_node	*build_stack(int *numbers, int count);
void	assign_ranks(t_node *stack, int size);
void	sort_array(int *arr, int size);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
int		count_numbers(char **av, int start);
int		ft_atoi_safe(char *str, int *error);
int		has_spaces(char *str);
void	free_split(char **split);
int		check_flag(char *str);
double	calculate_disorder(t_node *stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif