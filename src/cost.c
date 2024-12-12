/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:10:51 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 07:17:53 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_do_r_cost(t_stack **stack, int value)
{
	int	index;

	index = stack_index(*stack, value);
	if (index == -1)
		return (-1);
	return (index);
}

static int	get_do_rr_cost(t_stack **stack, int value)
{
	int	index;

	index = stack_index(*stack, value);
	if (index == -1)
		return (-1);
	return (stack_len(*stack) - index);
}

t_bool	get_rotation_way(t_stack *target, t_stack **stack)
{
	int		cost;
	int		cost_r;

	cost = get_do_r_cost(stack, target->value);
	cost_r = get_do_rr_cost(stack, target->value);
	if (cost == -1 || cost_r == -1)
		return (FALSE);
	if (cost <= cost_r)
		return (TRUE);
	return (FALSE);
}

int	get_move_cost(t_stack **a, t_stack *source
					, t_stack **b, t_stack *target)
{
	int		total_a;
	int		total_b;

	if (get_rotation_way(source, a) == get_rotation_way(target, b))
	{
		total_a = get_do_r_cost(a, source->value);
		total_b = get_do_r_cost(b, target->value);
		if (!get_rotation_way(source, a))
		{
			total_a = get_do_rr_cost(a, source->value);
			total_b = get_do_rr_cost(b, target->value);
		}
		if (total_a > total_b)
			return (total_a);
		return (total_b);
	}
	if (get_rotation_way(source, a))
		total_a = get_do_r_cost(a, source->value);
	else
		total_a = get_do_rr_cost(a, source->value);
	if (get_rotation_way(target, b))
		total_b = get_do_r_cost(b, target->value);
	else
		total_b = get_do_rr_cost(b, target->value);
	return (total_a + total_b + 1);
}
