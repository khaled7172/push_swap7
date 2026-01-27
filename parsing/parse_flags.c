/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:12:09 by kali              #+#    #+#             */
/*   Updated: 2026/01/27 14:21:25 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags parse_flags(int ac, char **av)
{
    t_flags flags;
    int i;

    flags.strategy = ADAPTIVE;
    flags.bench = 0;
    flags.num_start = 1;
    i = 1;
    while (i < ac)
    {
        if (av[i][0] == '-' && av[i][1] == '-')
        {
            i += 2;
            if (av[i] == --SIMPLE)
                flags.strategy = SIMPLE;
            if (av[i] == --MEDIUM)
                flags.strategy = MEDIUM;
            if (av[i] == --COMPLEX)
                flags.strategy = COMPLEX;
            flags.num_start++;
            if (av[i][0] == '-' && av[i][1] == '-')
            {
                i +=2;
                if (av[i] == bench)
                    flags.bench = 1;
            }
        }
        else
            break;
        i++;
    }
    return (flags);
}