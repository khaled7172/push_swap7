/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:26:38 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 10:26:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_to_stderr(char *str)
{
	ft_putstr_fd(str, 2);
}

void	print_number_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
}

void	print_disorder(double disorder)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)((disorder * 100 - whole) * 100);
	print_to_stderr("Disorder: ");
	print_number_fd(whole, 2);
	print_to_stderr(".");
	if (frac < 10)
		print_to_stderr("0");
	print_number_fd(frac, 2);
	print_to_stderr("%\n");
}

void	print_operations_part1(char *ops)
{
	print_to_stderr("sa: ");
	print_number_fd(c_op(ops, "sa"), 2);
	print_to_stderr(", sb: ");
	print_number_fd(c_op(ops, "sb"), 2);
	print_to_stderr(", ss: ");
	print_number_fd(c_op(ops, "ss"), 2);
	print_to_stderr(", pa: ");
	print_number_fd(c_op(ops, "pa"), 2);
	print_to_stderr(", pb: ");
	print_number_fd(c_op(ops, "pb"), 2);
	print_to_stderr(", ra: ");
	print_number_fd(c_op(ops, "ra"), 2);
}

void	print_operations_part2(char *ops)
{
	print_to_stderr(", rb: ");
	print_number_fd(c_op(ops, "rb"), 2);
	print_to_stderr(", rr: ");
	print_number_fd(c_op(ops, "rr"), 2);
	print_to_stderr(", rra: ");
	print_number_fd(c_op(ops, "rra"), 2);
	print_to_stderr(", rrb: ");
	print_number_fd(c_op(ops, "rrb"), 2);
	print_to_stderr(", rrr: ");
	print_number_fd(c_op(ops, "rrr"), 2);
	print_to_stderr("\n");
}
