/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:40:29 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/11 01:08:58 by arthur           ###   ########.fr       */
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

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	list_length(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
			{
				ft_putstr_fd("Error\n", ERROR);
				return (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
