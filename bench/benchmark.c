/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:18:50 by kali              #+#    #+#             */
/*   Updated: 2026/01/30 03:49:30 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy_name(int strategy)
{
	if (strategy == SIMPLE)
		ft_printf("Strategy: simple\n");
	else if (strategy == MEDIUM)
		ft_printf("Strategy: medium\n");
	else if (strategy == COMPLEX)
		ft_printf("Strategy: complex\n");
	else
		ft_printf("Strategy: adaptive\n");
}

static void	print_complexity(int strategy, double disorder)
{
	if (strategy == SIMPLE)
		ft_printf("Complexity: O(n²)\n");
	else if (strategy == MEDIUM)
		ft_printf("Complexity: O(n√n)\n");
	else if (strategy == COMPLEX)
		ft_printf("Complexity: O(n log n)\n");
	else
	{
		if (disorder < 0.2)
			ft_printf("Complexity: O(n)\n");
		else if (disorder < 0.5)
			ft_printf("Complexity: O(n√n)\n");
		else
			ft_printf("Complexity: O(n log n)\n");
	}
}

void	print_benchmark(double disorder, t_flags flags)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)((disorder * 100 - whole) * 100);
	ft_printf("Disorder: %d.%d%%\n", whole, frac);
	print_strategy_name(flags.strategy);
	print_complexity(flags.strategy, disorder);
}
