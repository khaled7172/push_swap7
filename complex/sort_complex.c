/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:13:15 by kali              #+#    #+#             */
/*   Updated: 2026/01/30 03:44:57 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}

static int	get_max_bits(int size)
{
	int	bits;
	int	max_num;

	max_num = size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_sort_bit(t_node **a, t_node **b, int bit_pos)
{
	int	size;
	int	i;
	int	bit;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		bit = get_bit((*a)->rank, bit_pos);
		if (bit == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	sort_complex(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	bit;

	size = stack_size(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_sort_bit(a, b, bit);
		bit++;
	}
}
