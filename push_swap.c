/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:40 by kali              #+#    #+#             */
/*   Updated: 2026/01/27 20:03:56 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_flags	flags;
	int		count;
	int		*numbers;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	flags = parse_flags(ac, av);
	if (flags.num_start >= ac)
		return (0);
	numbers = parse_numbers(av, flags.num_start, &count);
	while (i < count)
	{
		ft_printf("Number %d: %d\n", i, numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}
