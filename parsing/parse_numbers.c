/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:07:13 by kali              #+#    #+#             */
/*   Updated: 2026/01/27 19:30:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     *parse_numbers(char **av, int start, int *count)
{
    int i;
    int error;
    int num;
    
    i = 0;
    count = malloc (count_numbers + 1);
    while (av[start])
    {
    if (has_spaces(av[i]))
    {
        char **pieces = ft_split(av[i], ' ');
    }
    else
    //no spaces normal number, check if its a digit 
    {
        if(is_valid_number(av[i]))
        {
            num = ft_atoi_safe(av[i], &error);
            if (error)
            {
                print_error();
                exit(0);
            }
            count[i] = num;
            
            //make it handle long for int min and int max
            //if theres an error do something
        }
    }
    //now we check for dup
    }
}
int count_numbers(char **av, int start)
{
    int count;

    count = 0;
    while (av[start + count] != NULL)
        count++;
    return (count);
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
int ft_atoi_safe(char *str, int *error)
{
    //convert string to int
    //if overflow detected set *error = 1
    //returns number or 0 if error
    long result;
    int sign;
    int i;
    
    result = 0;
    sign = 1;
    i = 0;
    *error = 0;//we assume theres no error
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    //convert
    while (str[i] >= '0' && str[i] <= '9')
    {
        //check before multiplying
        if (result > (INT_MAX - (str[i] - '0')) / 10)
        {
            *error = 1;//OVERFLOW
            return (0);
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result *= sign;
    //final range check
    if (result > INT_MAX || result < INT_MIN)
    {
        *error = 1;
        return (0);
    }
    return ((int)result);
    
}
int has_duplicates(int *arr, int size)
{
    int i;
    int j;
    
    i = 0;
    while (i < size)
    {
        j = 1;
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
