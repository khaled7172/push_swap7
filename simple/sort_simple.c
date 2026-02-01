/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:05:23 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 10:21:00 by kali             ###   ########.fr       */
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

static void	sort_three_values(t_node **a, t_values v, char **ops)
{
	if (v.first > v.second && v.second < v.third && v.first < v.third)
		sa(a, ops);
	else if (v.first > v.second && v.second > v.third)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (v.first > v.second && v.second < v.third && v.first > v.third)
		ra(a, ops);
	else if (v.first < v.second && v.second > v.third && v.first < v.third)
	{
		sa(a, ops);
		ra(a, ops);
	}
	else if (v.first < v.second && v.second > v.third && v.first > v.third)
		rra(a, ops);
}

static void	sort_three(t_node **a, char **ops)
{
	t_values	v;

	if (stack_size(*a) != 3)
		return ;
	v.first = (*a)->value;
	v.second = (*a)->next->value;
	v.third = (*a)->next->next->value;
	sort_three_values(a, v, ops);
}

void	sort_simple(t_node **a, t_node **b, char **ops)
{
	int	size;
	int	min_pos;
	int	pushed;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	pushed = 0;
	while (size - pushed > 3)
	{
		min_pos = find_min_position(*a);
		rotate_to_top_a(a, min_pos, size - pushed, ops);
		pb(a, b, ops);
		pushed++;
	}
	sort_three(a, ops);
	while (*b)
		pa(a, b, ops);
}
