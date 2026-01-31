/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:20:04 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 01:21:47 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_node *stack)
{
	t_node	*current;
	t_node	*runner;
	int		inversions;
	int		total_pairs;

	inversions = 0;
	total_pairs = 0;
	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs++;
			if (current->value > runner->value)
				inversions++;
			runner = runner->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)inversions / total_pairs);
}
