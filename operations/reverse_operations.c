/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:55:02 by kali              #+#    #+#             */
/*   Updated: 2026/02/07 20:29:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b, char **ops)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "pb\n");
}

void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a, char **ops)
{
	rotate_stack(a);
	ft_printf("ra\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "ra\n");
}

void	rb(t_node **b, char **ops)
{
	rotate_stack(b);
	ft_printf("rb\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "rb\n");
}

void	rr(t_node **a, t_node **b, char **ops)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "rr\n");
}
