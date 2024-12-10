/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:15:05 by arthur            #+#    #+#             */
/*   Updated: 2024/12/10 23:54:32 by arthur           ###   ########.fr       */
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
