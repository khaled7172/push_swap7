/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:11:49 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/31 13:50:54 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert_digits(char *str, int start)
{
	long	result;
	int		i;

	result = 0;
	i = start;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi_safe(char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	*error = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = convert_digits(str, i);
	if (*error)
		return (0);
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		*error = 1;
	return ((int)result);
}
