/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:07:03 by kali              #+#    #+#             */
/*   Updated: 2026/02/06 21:07:17 by kali             ###   ########.fr       */
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
	int	percentage;

	percentage = (int)(disorder * 10000);
	print_to_stderr("Disorder: ");
	print_number_fd(percentage / 100, 2);
	print_to_stderr(".");
	if ((percentage % 100) < 10)
		print_to_stderr("0");
	print_number_fd(percentage % 100, 2);
	print_to_stderr("%\n");
}

static void	print_op(char *ops, char *name, int first)
{
	if (!first)
		print_to_stderr(", ");
	print_to_stderr(name);
	print_to_stderr(": ");
	print_number_fd(c_op(ops, name), 2);
}

void	print_all_operations(char *ops)
{
	print_op(ops, "sa", 1);
	print_op(ops, "sb", 0);
	print_op(ops, "ss", 0);
	print_op(ops, "pa", 0);
	print_op(ops, "pb", 0);
	print_op(ops, "ra", 0);
	print_op(ops, "rb", 0);
	print_op(ops, "rr", 0);
	print_op(ops, "rra", 0);
	print_op(ops, "rrb", 0);
	print_op(ops, "rrr", 0);
	print_to_stderr("\n");
}
