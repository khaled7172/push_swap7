/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:19:26 by rmsaed            #+#    #+#             */
/*   Updated: 2026/02/03 11:32:57 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert_digits(char *str, int start, int *error, int sign)
{
	long	result;
	long	max_allowed;
	int		i;

	result = 0;
	i = start;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == -1)
			max_allowed = (long)INT_MAX + 1;
		else
			max_allowed = INT_MAX;
		if (result > (max_allowed - (str[i] - '0')) / 10)
		{
			*error = 1;
			return (0);
		}
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
	result = convert_digits(str, i, error, sign);
	if (*error)
		return (0);
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		*error = 1;
	return ((int)result);
}
