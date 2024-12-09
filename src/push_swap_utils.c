/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:15:05 by arthur            #+#    #+#             */
/*   Updated: 2024/12/09 14:46:03 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("%s\n", "rr");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a, 0);
	reverse(b, 0);
	ft_printf("%s\n", "rrr");
}

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value && (*a)->value < (*a)->next->next->value)
		swap(*a, 'a');
	else if ((*a)->value > (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		swap(*a, 'a');
		reverse(a, 'a');
	}
	else if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->next->next->value)
		rotate(a, 'a');
	else if ((*a)->value < (*a)->next->value && (*a)->value > (*a)->next->next->value)
		reverse(a, 'a');
	else if ((*a)->value < (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		swap(*a, 'a');
		rotate(a, 'a');
	}
}

void sort_five(t_stack **a, t_stack **b)
{
	int	smin;
	int	min;

	smin = find_second_min(*a);
	min = find_min(*a);
    while (list_length(*a) > 3)
    {
        if ((*a)->value == min || (*a)->value == smin)
			push(a, b, 'b');
        else
			rotate(a, 'a');
    }
    sort_three(a);
	while (*b)
	{
	if ((*b)->value > (*a)->value)
 		rotate(a, 'a');
	else if ((*b)->next == NULL && (*a)->value != smin)
		reverse(a, 'a');
	else
		push(b, a, 'a');
	}
	if ((*a)->value > min)
		reverse(a, 'a');
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
