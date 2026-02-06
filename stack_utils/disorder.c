/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:20:04 by kali              #+#    #+#             */
/*   Updated: 2026/02/06 21:33:16 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_node *stack)
{
	t_node	*runner;
	int		inversions;
	int		total_pairs;
	int		size;

	size = stack_size(stack);
	total_pairs = size * (size - 1) / 2;
	if (total_pairs == 0)
		return (0.0);
	inversions = 0;
	while (stack)
	{
		runner = stack->next;
		while (runner)
		{
			if (stack->value > runner->value)
				inversions++;
			runner = runner->next;
		}
		stack = stack->next;
	}
	return ((double)inversions / total_pairs);
}
