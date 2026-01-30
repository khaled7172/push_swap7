/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:59:02 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:00:53 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_size(int size)
{
	int	chunk_size;
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	chunk_size = i;
	if (chunk_size < 1)
		chunk_size = 1;
	return (chunk_size);
}

int	find_max_position(t_node *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	current = stack;
	max = current->value;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}
