/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:40:29 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/10 16:07:39 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
int	find_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
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
void	push_to_position(t_stack **a, t_stack **b, char c)
{
	if (c == 'b')
	{
		while ((*a)->value > (*b)->value)
		{
			reverse(b, 'b');
		}
		push(a, b, 'b');
	}
	else if (c == 'a')
	{
		while ((*b)->value > (*a)->value)
		{
			reverse(a, 'a');
		}
		push(b, a, 'a');
	}
}
void	sort(t_stack **a, t_stack **b)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	min = find_min(*a);
	max = find_max(*a);
	while (list_length(*a) > 3 && i != 2)
	{
		push(a, b, 'b');
		i++;
	}
	while (list_length(*a) > 3)
 		push_to_position(a, b, 'b');
	sort_three(a);
	/* while (*b)
	{
		while ((*b)->value == max)
		{
			if ((*a)->value == min)
				push(b, a, 'a');
			else
				reverse(a, 'a');
		}
		while ((*b)->value > (*a)->value)
		{
			reverse(a, 'a');
		}
		push(b, a, 'a');
	} */

}
