/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:40 by kali              #+#    #+#             */
/*   Updated: 2026/01/30 21:13:37 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(char **argv, t_flags flags, t_node **a, t_node **b)
{
	int	*numbers;
	int	count;

	numbers = parse_numbers(argv, flags.num_start, &count);
	*a = build_stack(numbers, count);
	*b = NULL;
	free(numbers);
	assign_ranks(*a, count);
}

static void	execute_sort(t_node **a, t_node **b, t_flags flags, double disorder)
{
	if (flags.strategy == SIMPLE)
		sort_simple(a, b);
	else if (flags.strategy == MEDIUM)
		sort_medium(a, b);
	else if (flags.strategy == COMPLEX)
		sort_complex(a, b);
	else
		sort_adaptive(a, b, disorder);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_node	*stack_a;
	t_node	*stack_b;
	double	disorder;

	if (argc < 2)
		return (0);
	flags = parse_flags(argc, argv);
	if (flags.num_start >= argc)
		return (0);
	init_stacks(argv, flags, &stack_a, &stack_b);
	disorder = calculate_disorder(stack_a);
	if (flags.bench)
		print_benchmark(disorder, flags);
	execute_sort(&stack_a, &stack_b, flags, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
