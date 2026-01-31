/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:17:37 by kali              #+#    #+#             */
/*   Updated: 2026/01/31 23:20:56 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b, double disorder)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
		sort_simple(a, b);
	else if (size <= 5)
		sort_simple(a, b);
	else if (size <= 100 && disorder < 0.6)
		sort_medium(a, b);
	else if (size <= 100)
		sort_complex(a, b);
	else if (disorder < 0.7)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
