/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:18:50 by kali              #+#    #+#             */
/*   Updated: 2026/02/06 21:10:18 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy_name(int strategy, double disorder)
{
	print_to_stderr("Strategy: ");
	if (strategy == SIMPLE)
		print_to_stderr("simple / Complexity: O(n²)\n");
	else if (strategy == MEDIUM)
		print_to_stderr("medium / Complexity: O(n√n)\n");
	else if (strategy == COMPLEX)
		print_to_stderr("complex / Complexity: O(n log n)\n");
	else
	{
		print_to_stderr("adaptive / Complexity: ");
		if (disorder < 0.2)
			print_to_stderr("O(n²)\n");
		else if (disorder < 0.5)
			print_to_stderr("O(n√n)\n");
		else
			print_to_stderr("O(n log n)\n");
	}
}

void	print_benchmark(double disorder, t_flags flags, char *ops)
{
	print_disorder(disorder);
	print_strategy_name(flags.strategy, disorder);
	print_to_stderr("Total operations: ");
	print_number_fd(total_ops(ops), 2);
	print_to_stderr("\n");
	print_all_operations(ops);
}
