/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:40 by kali              #+#    #+#             */
/*   Updated: 2026/01/28 20:34:44 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_flags flags;
    int     *numbers;
    int     count;
    t_node  *stack_a;
    t_node  *current;
    
    if (argc < 2)
        return (0);
    flags = parse_flags(argc, argv);
    if (flags.num_start >= argc)
        return (0);
    numbers = parse_numbers(argv, flags.num_start, &count);
    stack_a = build_stack(numbers, count);
    free(numbers);
    assign_ranks(stack_a, count);
    current = stack_a;
    while (current)
    {
        ft_printf("Value: %d, Rank: %d\n", current->value, current->rank);
        current = current->next;
    }
    
    free_stack(&stack_a);
    return (0);
}

