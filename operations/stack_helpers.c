/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 02:39:18 by kali              #+#    #+#             */
/*   Updated: 2026/01/29 02:42:52 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_stack(t_node **stack)
{
    t_node *first;
    t_node *last;
    
    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}
static void reverse_rotate_stack(t_node **stack)
{
    t_node *last;
    t_node *second_last;
    
    if (!*stack || !(*stack)->next)
        return;
    last = *stack;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}
void	rr(t_node **a, t_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
void	rrr(t_node **a, t_node **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
}
