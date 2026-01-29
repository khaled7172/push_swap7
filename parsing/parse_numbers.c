/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:07:13 by kali              #+#    #+#             */
/*   Updated: 2026/01/30 01:22:41 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert_digits(char *str, int start, int *error)
{
	long	result;
	int		i;

	result = 0;
	i = start;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (INT_MAX - (str[i] - '0')) / 10)
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	count_numbers(char **av, int start)
{
    int total;
	int i;
	char **pieces;
	int j;

    total = 0;
	i = start;
    while (av[i])
	{
		if (has_spaces(av[i]))
		{
			pieces = ft_split(av[i], ' ');
			j = 0;
			while (pieces[j])
			{
				total++;
				j++;
			}
			free_split(pieces);
		}
		else
			total++;
		i++;
	}
    return (total);
}

int is_valid_number(char *str)
{
    int i;

    i = 0;
    //check for sign
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return (0);//only contains '+' or '-' alone
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);//valid number
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
	result = convert_digits(str, i, error);
	if (*error)
		return (0);
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		*error = 1;
	return ((int)result);
}
int has_duplicates(int *arr, int size)
{
    int i;
    int j;
    
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
    
}
int has_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}
void	free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

