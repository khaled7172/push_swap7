/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:43:52 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 01:30:08 by kali             ###   ########.fr       */
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

static void	execute_sort(t_node **a, t_node **b, t_flags *f, char **ops)
{
	if (f->strategy == SIMPLE)
		sort_simple(a, b, ops);
	else if (f->strategy == MEDIUM)
		sort_medium(a, b, ops);
	else if (f->strategy == COMPLEX)
		sort_complex(a, b, ops);
	else
		sort_adaptive(a, b, f->disorder, ops);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_node	*stack_a;
	t_node	*stack_b;
	char	*ops;

	if (argc < 2)
		return (0);
	flags = parse_flags(argc, argv);
	if (flags.num_start >= argc)
		return (0);
	init_stacks(argv, flags, &stack_a, &stack_b);
	flags.disorder = calculate_disorder(stack_a);
	ops = NULL;
	execute_sort(&stack_a, &stack_b, &flags, &ops);
	if (flags.bench)
		print_benchmark(flags.disorder, flags, ops);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ops)
		free(ops);
	return (0);
}
