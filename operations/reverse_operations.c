/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 02:22:25 by kali              #+#    #+#             */
/*   Updated: 2026/01/29 02:42:39 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;
	
	if (!*a)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
	
}

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}
void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!*b || !(*b)->next)
		return;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
}
void	rra(t_node **a)
{
	t_node	*last;
	t_node	*second_last;
	
	if (!*a || !(*a)->next)
		return;
	last = *a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}
void	rrb(t_node **b)
{
	t_node	*last;
	t_node	*second_last;
	
	if (!*b || !(*b)->next)
		return;
	last = *b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
}
