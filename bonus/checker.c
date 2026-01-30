/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:20:03 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:20:09 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_swap_push(char *op, t_node **a, t_node **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap_no_print(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap_no_print(b);
	else if (ft_strcmp(op, "ss\n") == 0)
	{
		swap_no_print(a);
		swap_no_print(b);
	}
	else if (ft_strcmp(op, "pa\n") == 0)
		push_no_print(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		push_no_print(b, a);
}

static void	execute_rotate(char *op, t_node **a, t_node **b)
{
	if (ft_strcmp(op, "ra\n") == 0)
		rotate_no_print(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate_no_print(b);
	else if (ft_strcmp(op, "rr\n") == 0)
	{
		rotate_no_print(a);
		rotate_no_print(b);
	}
}

static void	execute_reverse_rotate(char *op, t_node **a, t_node **b)
{
	if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate_no_print(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate_no_print(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
	{
		reverse_rotate_no_print(a);
		reverse_rotate_no_print(b);
	}
}

static void	execute_operation(char *op, t_node **a, t_node **b)
{
	execute_swap_push(op, a, b);
	execute_rotate(op, a, b);
	execute_reverse_rotate(op, a, b);
	if (ft_strcmp(op, "sa\n") && ft_strcmp(op, "sb\n") && ft_strcmp(op, "ss\n")
		&& ft_strcmp(op, "pa\n") && ft_strcmp(op, "pb\n")
		&& ft_strcmp(op, "ra\n") && ft_strcmp(op, "rb\n")
		&& ft_strcmp(op, "rr\n") && ft_strcmp(op, "rra\n")
		&& ft_strcmp(op, "rrb\n") && ft_strcmp(op, "rrr\n"))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
