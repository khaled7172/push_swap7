/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:13:21 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:13:27 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_a(int target_pos, int size_a)
{
	if (target_pos <= size_a / 2)
		return (target_pos);
	else
		return (size_a - target_pos);
}

int	calculate_cost_b(int pos_b, int size_b)
{
	if (pos_b <= size_b / 2)
		return (pos_b);
	else
		return (size_b - pos_b);
}

int	calculate_total_cost(t_node *a, t_node *b, int pos_b)
{
	t_node	*b_current;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	int		i;

	b_current = b;
	i = 0;
	while (i < pos_b)
	{
		b_current = b_current->next;
		i++;
	}
	target_pos = get_target_pos(a, b_current->value);
	cost_a = calculate_cost_a(target_pos, stack_size(a));
	cost_b = calculate_cost_b(pos_b, stack_size(b));
	return (cost_a + cost_b);
}
