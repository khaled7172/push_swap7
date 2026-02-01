/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmsaed <rmsaed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:19:15 by rmsaed            #+#    #+#             */
/*   Updated: 2026/02/01 19:19:21 by rmsaed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(int *numbers, char **pieces)
{
	if (numbers)
		free(numbers);
	if (pieces)
		free_split(pieces);
	print_error();
	exit(1);
}

static void	process_piece(char *piece, int *numbers, int *index, char **pieces)
{
	int	error;

	if (!is_valid_number(piece))
		error_exit(numbers, pieces);
	numbers[(*index)++] = ft_atoi_safe(piece, &error);
	if (error)
		error_exit(numbers, pieces);
}

static void	process_split_arg(char *arg, int *numbers, int *index)
{
	char	**pieces;
	int		j;

	pieces = ft_split(arg, ' ');
	if (!pieces)
		error_exit(numbers, NULL);
	j = 0;
	while (pieces[j])
	{
		process_piece(pieces[j], numbers, index, pieces);
		j++;
	}
	free_split(pieces);
}

static void	process_single_arg(char *arg, int *numbers, int *index)
{
	int	error;

	if (!is_valid_number(arg))
		error_exit(numbers, NULL);
	numbers[(*index)++] = ft_atoi_safe(arg, &error);
	if (error)
		error_exit(numbers, NULL);
}

void	fill_numbers(char **av, int start, int *numbers)
{
	int	arg_idx;
	int	index;

	arg_idx = start;
	index = 0;
	while (av[arg_idx])
	{
		if (has_spaces(av[arg_idx]))
			process_split_arg(av[arg_idx], numbers, &index);
		else
			process_single_arg(av[arg_idx], numbers, &index);
		arg_idx++;
	}
}
