/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:22:27 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 01:22:28 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b, double disorder, char **ops)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		sort_simple(a, b, ops);
	else if (size <= 5)
		sort_simple(a, b, ops);
	else if (size <= 100 && disorder < 0.5)
		sort_medium(a, b, ops);
	else
		sort_complex(a, b, ops);
}
