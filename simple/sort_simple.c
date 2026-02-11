/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmsaed <rmsaed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:05:23 by kali              #+#    #+#             */
/*   Updated: 2026/02/11 22:59:42 by rmsaed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	v.first = (*a)->value;
	v.second = (*a)->next->value;
	v.third = (*a)->next->next->value;
	sort_three_values(a, v, ops);
}

static void	sort_large(t_node **a, t_node **b, int size, char **ops)
{
	int	min_pos;
	int	pushed;

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

void	sort_simple(t_node **a, t_node **b, char **ops)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a, ops);
	else if (size == 3)
		sort_three(a, ops);
	else
		sort_large(a, b, size, ops);
}
