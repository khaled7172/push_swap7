/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:20:17 by kali              #+#    #+#             */
/*   Updated: 2026/01/29 20:22:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_no_print(t_node **stack)
{
    t_node *first;
    t_node *second;
    
    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void push_no_print(t_node **dest, t_node **src)
{
    t_node *tmp;
    
    if (!*src)
        return;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
}

void rotate_no_print(t_node **stack)
{
    t_node *first;
    t_node *last;
    
    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void reverse_rotate_no_print(t_node **stack)
{
    t_node *last;
    t_node *second_last;
    
    if (!*stack || !(*stack)->next)
        return;
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
/*
To test checker:
# Generate operations and test
./push_swap 3 2 1 > ops.txt
cat ops.txt | ./checker 3 2 1
# Should output: OK

# Wrong operations
echo "sa" | ./checker 3 2 1
# Should output: KO (not fully sorted)

# Pipe directly
./push_swap 4 2 3 1 | ./checker 4 2 3 1
# Should output: OK
//update the makefile if you want to include the bonus
BONUS_NAME = checker
BONUS_SRCS = checker.c \
             # ... include all your utility files

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
*/
/*
Final testing checklist:
# Test each strategy
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Test benchmark
./push_swap --bench --simple 3 2 1

# Test 100 numbers
./push_swap $(shuf -i 1-100 -n 100) | wc -l
# Should be < 2000

# Test 500 numbers
./push_swap $(shuf -i 1-500 -n 500) | wc -l
# Should be < 12000

# Test checker
./push_swap 3 2 1 | ./checker 3 2 1
# Should output: OK

# Test errors
./push_swap 3 2 3  # Duplicate
./push_swap abc    # Invalid
*/