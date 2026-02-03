/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:20:04 by kali              #+#    #+#             */
/*   Updated: 2026/02/03 10:45:42 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_node *stack)
{
	t_node	*current;
	t_node	*runner;
	int		inversions;
	int		total_pairs;
	int		size;

	inversions = 0;
	size = stack_size(stack);
	total_pairs = size * (size - 1) / 2;
	if (total_pairs == 0)
		return (0.0);
	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value > runner->value)
				inversions++;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((double)inversions / total_pairs);
}
