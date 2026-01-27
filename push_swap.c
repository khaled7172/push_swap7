/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:40 by kali              #+#    #+#             */
/*   Updated: 2026/01/27 18:33:21 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_flags flags;
    int     count;
    int     *numbers;
    
    if (ac < 2)
        return (0);//not passing args so not output but not error either
    flags = parse_flags(ac, av);
    if (flags.num_start >= ac)
        return (0);
    numbers = parse_numbers(av, flags.num_start, &count);
    for (int i =0; i < count; i++)
        ft_printf("Number %d: %d\n", i, numbers[i]);
    free(numbers);
    return (0);
}