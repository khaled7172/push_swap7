/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:40 by kali              #+#    #+#             */
/*   Updated: 2026/01/27 14:23:01 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_flags flags;
    
    if (ac < 2)
        return (0);//not passing args so not output but not error either
    flags = parse_flags(ac, av);
    
    // For now, just test if it works
    ft_printf("Strategy: %d\n", flags.strategy);
    ft_printf("Bench: %d\n", flags.bench);
    ft_printf("Numbers start at: %d\n", flags.num_start);
    
    return (0);
}