/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:07:15 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 07:08:31 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_biggest(t_stack *stack)
{
	int		number;
	int		biggest;
	t_stack	*biggest_ptr;

	biggest_ptr = stack;
	while (stack)
	{
		number = stack->value;
		biggest = biggest_ptr->value;
		if (number > biggest)
			biggest_ptr = stack;
		stack = stack->next;
	}
	return (biggest_ptr);
}

t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*biggest_ptr;

	biggest_ptr = stack;
	while (stack)
	{
		if (stack->value < biggest_ptr->value)
			biggest_ptr = stack;
		stack = stack->next;
	}
	return (biggest_ptr);
}

t_stack	*get_smaller(t_stack *stack, int target)
{
	t_stack	*smaller_ptr;

	smaller_ptr = stack;
	while (stack)
	{
		if (stack->value <= target)
		{
			if (target < smaller_ptr->value)
				smaller_ptr = stack;
			else if (stack->value > smaller_ptr->value)
				smaller_ptr = stack;
		}
		stack = stack->next;
	}
	return (smaller_ptr);
}

t_stack	*get_bigger(t_stack *stack, int target)
{
	t_stack	*smaller_ptr;

	smaller_ptr = stack;
	while (stack)
	{
		if (stack->value >= target)
		{
			if (target > smaller_ptr->value)
				smaller_ptr = stack;
			else if (stack->value < smaller_ptr->value)
				smaller_ptr = stack;
		}
		stack = stack->next;
	}
	return (smaller_ptr);
}
