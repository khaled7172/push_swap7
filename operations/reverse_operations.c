/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:55:02 by kali              #+#    #+#             */
/*   Updated: 2026/02/06 20:56:17 by kali             ###   ########.fr       */
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
