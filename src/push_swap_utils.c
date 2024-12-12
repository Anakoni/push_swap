/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:15:05 by arthur            #+#    #+#             */
/*   Updated: 2024/12/11 00:38:53 by arthur           ###   ########.fr       */
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

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	fin;

	i = 0;
	sign = 1;
	fin = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		fin = fin * 10 + (str[i] - '0');
		i++;
	}
	return (sign * fin);
}
