/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:14:33 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:14:39 by khhammou         ###   ########.fr       */
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
