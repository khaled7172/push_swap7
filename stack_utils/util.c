/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmsaed <rmsaed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:43:07 by kali              #+#    #+#             */
/*   Updated: 2026/02/03 22:48:24 by rmsaed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = 0;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_node **head, t_node *new)
{
	t_node	*current;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

t_node	*build_stack(int *numbers, int count)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	if (!numbers || count <= 0)
		return (NULL);
	stack = NULL;
	i = 0;
	while (i < count)
	{
		new_node = create_node(numbers[i]);
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_node_back(&stack, new_node);
		i++;
	}
	return (stack);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
