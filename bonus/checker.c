/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:19:22 by kali              #+#    #+#             */
/*   Updated: 2026/01/30 01:25:34 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void execute_operation(char *op, t_node **a, t_node **b)
{
    if (ft_strcmp(op, "sa\n") == 0)
        swap_no_print(a);
    else if (ft_strcmp(op, "sb\n") == 0)
        swap_no_print(b);
    else if (ft_strcmp(op, "ss\n") == 0)
    {
        swap_no_print(a);
        swap_no_print(b);
}
else if (ft_strcmp(op, "pa\n") == 0)
    push_no_print(a, b);
else if (ft_strcmp(op, "pb\n") == 0)
    push_no_print(a, b);
else if (ft_strcmp(op, "ra\n") == 0)
    rotate_no_print(a);
else if (ft_strcmp(op, "rb\n") == 0)
    rotate_no_print(b);
else if (ft_strcmp(op, "rr\n") == 0)
{
        rotate_no_print(a);
        rotate_no_print(b);
}
else if (ft_strcmp(op, "rra\n") == 0)
    reverse_rotate_no_print(a);
else if (ft_strcmp(op, "rrb\n") == 0)
    reverse_rotate_no_print(b);
else if (ft_strcmp(op, "rrr\n") == 0)
    {
            reverse_rotate_no_print(a);
            reverse_rotate_no_print(b);
    }
    else
    {
            write(2, "Error\n", 6);
            exit(1);
    }
}

static intis_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     *numbers;
    int     count;
    char    *line;
    
    if (argc < 2)
        return (0);
    numbers = parse_numbers(argv, 1, &count);
    stack_a = build_stack(numbers, count);
    stack_b = NULL;
    free(numbers);
    line = get_next_line(0);
    while (line)
    {
        execute_operation(line, &stack_a, &stack_b);
        free(line);
        line = get_next_line(0);
    }
    if (is_sorted(stack_a) && !stack_b)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
