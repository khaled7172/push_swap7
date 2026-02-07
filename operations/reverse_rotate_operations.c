/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:43:37 by kali              #+#    #+#             */
/*   Updated: 2026/02/07 20:28:53 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
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

void	rra(t_node **a, char **ops)
{
	reverse_rotate_stack(a);
	ft_printf("rra\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "rra\n");
}

void	rrb(t_node **b, char **ops)
{
	reverse_rotate_stack(b);
	ft_printf("rrb\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "rrb\n");
}

void	rrr(t_node **a, t_node **b, char **ops)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
	if (ops)
		*ops = ft_strjoin_free(*ops, "rrr\n");
}
