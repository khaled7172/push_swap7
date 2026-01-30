/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:13:02 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:13:08 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_pos(t_node *a, int b_value)
{
	t_node	*current;
	int		target_value;
	int		pos;
	int		target_pos;

	current = a;
	target_value = 2147483647;
	pos = 0;
	target_pos = 0;
	while (current)
	{
		if (current->value > b_value && current->value < target_value)
		{
			target_value = current->value;
			target_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (target_pos);
}

static void	execute_move(t_node **a, t_node **b, int pos_b)
{
	int	target_pos;
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	target_pos = get_target_pos(*a, (*b)->value);
	rotate_to_top(b, pos_b, size_b);
	rotate_to_top(a, target_pos, size_a);
	pa(a, b);
}

static void	final_rotation(t_node **a)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(*a);
	size = stack_size(*a);
	rotate_to_top(a, min_pos, size);
}

static int	find_cheapest(t_node *a, t_node *b)
{
	int	pos;
	int	cheapest_pos;
	int	min_cost;
	int	cost;

	pos = 0;
	cheapest_pos = 0;
	min_cost = 2147483647;
	while (pos < stack_size(b))
	{
		cost = calculate_total_cost(a, b, pos);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_pos = pos;
		}
		pos++;
	}
	return (cheapest_pos);
}

void	sort_turkish(t_node **a, t_node **b)
{
	int	size;
	int	cheapest;

	size = stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
	{
		cheapest = find_cheapest(*a, *b);
		execute_move(a, b, cheapest);
	}
	final_rotation(a);
}
