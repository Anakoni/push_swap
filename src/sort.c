/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 06:58:18 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 07:16:10 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
		swap(a, b, 'a');
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		swap(a, b, 'a');
		reverse(a, 'a');
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		rotate(a, 'a');
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		reverse(a, 'a');
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		swap(a, b, 'a');
		rotate(a, 'a');
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*temp_target;

	while (stack_len(*a) > 3)
		push(a, b, 'b');
	sort_three(a, b);
	while (*b)
	{
		if (is_max((*b)->value, *a))
			temp_target = get_smallest(*a);
		else
			temp_target = get_bigger(*a, (*b)->value);
		while (*a != temp_target)
		{
			if (get_rotation_way(temp_target, a))
				rotate(a, 'a');
			else if (!get_rotation_way(temp_target, a))
				reverse(a, 'a');
		}
		push(b, a, 'a');
	}
	temp_target = get_smallest(*a);
	while (*a != temp_target)
		rotate(a, 'a');
}
