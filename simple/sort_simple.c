/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:05:23 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:05:53 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_node *stack)
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

static void	rotate_to_top(t_node **stack, int pos, int size)
{
	int	rotations;

	if (pos <= size / 2)
	{
		rotations = pos;
		while (rotations--)
			ra(stack);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rra(stack);
	}
}

static void	sort_three_helper(t_node **a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(*a) != 3)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	sort_three_helper(a, first, second, third);
}

void	sort_simple(t_node **a, t_node **b)
{
	int	size;
	int	min_pos;
	int	pushed;

	size = stack_size(*a);
	pushed = 0;
	while (size - pushed > 3)
	{
		min_pos = find_min_position(*a);
		rotate_to_top(a, min_pos, size - pushed);
		pb(a, b);
		pushed++;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
