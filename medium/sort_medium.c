/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmsaed <rmsaed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:00:34 by kali              #+#    #+#             */
/*   Updated: 2026/02/12 00:20:41 by rmsaed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_chunk(int rank, int chunk_num, int chunk_size)
{
	int	min_rank;
	int	max_rank;

	min_rank = chunk_num * chunk_size;
	max_rank = min_rank + chunk_size - 1;
	if (rank >= min_rank && rank <= max_rank)
		return (1);
	return (0);
}

static int	find_chunk_element(t_node *stack, int chunk_num, int chunk_size)
{
	t_node	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current)
	{
		if (is_in_chunk(current->rank, chunk_num, chunk_size))
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

static void	push_chunk(t_node **a, t_node **b, t_chunk_info c, char **ops)
{
	int	pos;
	int	size;

	while (1)
	{
		pos = find_chunk_element(*a, c.chunk_num, c.chunk_size);
		if (pos == -1)
			break ;
		size = stack_size(*a);
		rotate_to_top_a(a, pos, size, ops);
		pb(a, b, ops);
	}
}

static void	push_back_sorted(t_node **a, t_node **b, char **ops)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		max_pos = find_max_position(*b);
		size = stack_size(*b);
		rotate_to_top_b(b, max_pos, size, ops);
		pa(a, b, ops);
	}
}

void	sort_medium(t_node **a, t_node **b, char **ops)
{
	int				size;
	int				num_chunks;
	int				i;
	t_chunk_info	c;

	size = stack_size(*a);
	c.chunk_size = calculate_chunk_size(size);
	num_chunks = (size + c.chunk_size - 1) / c.chunk_size;
	i = 0;
	while (i < num_chunks)
	{
		c.chunk_num = i;
		push_chunk(a, b, c, ops);
		i++;
	}
	push_back_sorted(a, b, ops);
}
