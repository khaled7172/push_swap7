/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:22:56 by kali              #+#    #+#             */
/*   Updated: 2026/01/28 20:55:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_node *stack, int size)
{
	int		*sorted;
	t_node	*current;
	int		i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	current = stack;
	i = 0;
	while (current)
	{
		sorted[i++] = current->value;
		current = current->next;
	}
	sort_array(sorted, size);
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size && sorted[i] != current->value)
			i++;
		current->rank = i;
		current = current->next;
	}
	free(sorted);
}
void sort_array(int *arr, int size)
{
    int i;
	int	j;
	
	i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

