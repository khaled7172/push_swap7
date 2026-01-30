/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 03:55:54 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 03:57:42 by khhammou         ###   ########.fr       */
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

void	rotate_to_top_b(t_node **b, int pos, int size)
{
	int	rotations;

	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations--)
			rb(b);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rrb(b);
	}
}

void	rotate_to_top_a(t_node **a, int pos, int size)
{
	int	rotations;

	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations--)
			ra(a);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rra(a);
	}
}
