/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmsaed <rmsaed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:17:37 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 20:55:01 by rmsaed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_adaptive(t_node **a, t_node **b, double disorder, char **ops)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b, ops);
		return (SIMPLE);
	}
	else if (size <= 100 && disorder < 0.5)
	{
		sort_medium(a, b, ops);
		return (MEDIUM);
	}
	else
	{
		sort_complex(a, b, ops);
		return (COMPLEX);
	}
}
