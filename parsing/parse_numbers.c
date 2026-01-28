/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:07:13 by kali              #+#    #+#             */
/*   Updated: 2026/01/28 02:51:16 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     *parse_numbers(char **av, int start, int *count)
{
	int	*numbers;
    int index;
    int total;
	int	arg_idx;
	int error;
	char **pieces;
	int j;
    
	total = count_numbers(av, start);
    numbers = malloc (sizeof(int) * total);
	if (!numbers)
		return (NULL);
	index = 0;//position in array
	arg_idx = start;//curr arg
    while (av[arg_idx])
    {
    	if (has_spaces(av[arg_idx]))
    	{
        	pieces = ft_split(av[arg_idx], ' ');
			j = 0;
			while (pieces[j])
			{
				if(!is_valid_number(pieces[j]))
				{
					free_split(pieces);
					free(numbers);
					print_error();
					exit(1);
				}
				numbers[index++] = ft_atoi_safe(pieces[j], &error);
				if (error)
				{
					free_split(pieces);
					free(numbers);
					print_error();
					exit(1);
				}
				j++;
			}
			free_split(pieces);
    	}
    	else
    //no spaces normal number, check if its a digit 
    	{	
        	if(!is_valid_number(av[arg_idx]))
			{
				free(numbers);
				print_error();
				exit(1);
			}
            numbers[index++] = ft_atoi_safe(av[arg_idx], &error);
            	if (error)
            	{
					free(numbers);
            	    print_error();
            	    exit(1);
            	}
			}
			arg_idx++;
    }
    //now we check for dup
	if (has_duplicates(numbers, total))
	{
		free(numbers);
		print_error();
		exit(1);
	}
	*count = total;
	return (numbers);
}


int count_numbers(char **av, int start)
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