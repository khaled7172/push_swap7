/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:19:09 by rmsaed            #+#    #+#             */
/*   Updated: 2026/02/03 10:30:40 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_numbers(char **av, int start, int *count)
{
	int	*numbers;
	int	total;

	total = count_numbers(av, start);
	numbers = malloc(sizeof(int) * total);
	if (!numbers)
		return (NULL);
	fill_numbers(av, start, numbers);
	if (has_duplicates(numbers, total))
	{
		free(numbers);
		print_error();
		exit(1);
	}
	*count = total;
	return (numbers);
}
