/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmsaed <rmsaed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:40 by kali              #+#    #+#             */
/*   Updated: 2026/02/04 22:32:50 by rmsaed           ###   ########.fr       */
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

static void	execute_sort(t_sort_data *data)
{
	int	actual_strategy;

	if (data->flags->strategy == SIMPLE)
		sort_simple(data->a, data->b, data->ops);
	else if (data->flags->strategy == MEDIUM)
		sort_medium(data->a, data->b, data->ops);
	else if (data->flags->strategy == COMPLEX)
		sort_complex(data->a, data->b, data->ops);
	else
	{
		actual_strategy = sort_adaptive(data->a, data->b,
				data->disorder, data->ops);
		data->flags->strategy = actual_strategy;
	}
}

static void	run_push_swap(t_flags flags, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		*ops;
	t_sort_data	data;

	init_stacks(argv, flags, &stack_a, &stack_b);
	ops = NULL;
	data.a = &stack_a;
	data.b = &stack_b;
	data.flags = &flags;
	data.disorder = calculate_disorder(stack_a);
	data.ops = &ops;
	execute_sort(&data);
	if (flags.bench)
		print_benchmark(data.disorder, flags, ops);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ops)
		free(ops);
}

int	main(int argc, char **argv)
{
	t_flags	flags;

	if (argc < 2)
		return (0);
	flags = parse_flags(argc, argv);
	if (flags.num_start >= argc)
		return (0);
	run_push_swap(flags, argv);
	return (0);
}
