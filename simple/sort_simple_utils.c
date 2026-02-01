/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 03:55:54 by kali              #+#    #+#             */
/*   Updated: 2026/02/02 01:41:00 by kali             ###   ########.fr       */
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
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
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
	int	rotations;

	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations--)
			ra(stack, ops);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rra(stack, ops);
	}
}
