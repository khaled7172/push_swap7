/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 03:55:54 by kali              #+#    #+#             */
/*   Updated: 2026/02/06 21:05:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min_position(t_node *stack)
{
	int		min;
	int		pos;
	int		min_pos;

	if (!stack)
		return (-1);
	min = stack->value;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_to_top_b(t_node **b, int pos, int size, char **ops)
{
	int	rotations;

	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations--)
			rb(b, ops);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rrb(b, ops);
	}
}

void	rotate_to_top_a(t_node **a, int pos, int size, char **ops)
{
	int	rotations;

	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations--)
			ra(a, ops);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rra(a, ops);
	}
}

void	rotate_to_top(t_node **stack, int pos, int size, char **ops)
{
	rotate_to_top_a(stack, pos, size, ops);
}
