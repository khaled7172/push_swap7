/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:17:37 by kali              #+#    #+#             */
/*   Updated: 2026/01/29 20:17:56 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_adaptive(t_node **a, t_node **b, double disorder)
{
    if (disorder < 0.2)
        sort_simple(a, b);
    else if (disorder < 0.5)
        sort_medium(a, b);
    else
        sort_complex(a, b);
}
