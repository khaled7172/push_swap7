/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:20:32 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:20:46 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_checker(char **argv, t_node **a, t_node **b, int *count)
{
	int	*numbers;

	numbers = parse_numbers(argv, 1, count);
	*a = build_stack(numbers, *count);
	*b = NULL;
	free(numbers);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;
	char	*line;

	if (argc < 2)
		return (0);
	init_checker(argv, &stack_a, &stack_b, &count);
	line = get_next_line(0);
	while (line)
	{
		execute_operation(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
