/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:15:05 by arthur            #+#    #+#             */
/*   Updated: 2024/12/09 13:24:46 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value && (*a)->value < (*a)->next->next->value)
		swap(*a);
	else if ((*a)->value > (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		swap(*a);
		reverse(a);
	}
	else if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value)
		rotate(a);
	else if ((*a)->value < (*a)->next->value && (*a)->value > (*a)->next->next->value)
		reverse(a);
	else if ((*a)->value < (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		swap(*a);
		rotate(a);
	}
}

void sort_five(t_stack **a, t_stack **b)
{
    while (list_length(*a) > 3)
    {
        if ((*a)->value == find_min(*a) || (*a)->value == find_second_min(*a))
            push(a, b);
        else
            rotate(a);
    }
    sort_three(a);
	while (*b)
	{
	if ((*b)->value > (*a)->value)
 		rotate(a);
	else
		push(b, a);
	}
	if ((*a)->value > find_min(*a))
		reverse(a);
}

int	find_second_min(t_stack *stack)
{
	int	min;
	int	second_min;

	min = find_min(stack);
	second_min = __INT_MAX__;
	while (stack)
	{
		if (stack->value > min && stack->value < second_min)
			second_min = stack->value;
		stack = stack->next;
	}
	return (second_min);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int list_length(t_stack *stack)
{
    int length = 0;
    
    while (stack) 
    {
        length++;
        stack = stack->next;
    }
    
    return length;
}