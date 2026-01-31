/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:43:15 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 00:43:17 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:01:22 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 00:00:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_stack(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void    sa(t_node **a, char **ops)
{
    t_node  *first;
    t_node  *second;

    if (!*a || !(*a)->next)
        return ;
    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    ft_printf("sa\n");
    if (ops)
        *ops = ft_strjoin_free(*ops, "sa\n");
}

void    sb(t_node **b, char **ops)
{
    t_node  *first;
    t_node  *second;

    if (!*b || !(*b)->next)
        return ;
    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_printf("sb\n");
    if (ops)
        *ops = ft_strjoin_free(*ops, "sb\n");
}

void    ss(t_node **a, t_node **b, char **ops)
{
    swap_stack(a);
    swap_stack(b);
    ft_printf("ss\n");
    if (ops)
        *ops = ft_strjoin_free(*ops, "ss\n");
}

void    pa(t_node **a, t_node **b, char **ops)
{
    t_node  *tmp;

    if (!*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    ft_printf("pa\n");
    if (ops)
        *ops = ft_strjoin_free(*ops, "pa\n");
}
