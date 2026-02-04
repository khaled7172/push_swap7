/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:59:02 by kali              #+#    #+#             */
/*   Updated: 2026/02/04 10:22:22 by kali             ###   ########.fr       */
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
	int		max;
	int		pos;
	int		max_pos;

	if (!stack)
		return (-1);
	max = stack->value;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}
