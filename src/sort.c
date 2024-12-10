/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:50:16 by arthur            #+#    #+#             */
/*   Updated: 2024/12/11 00:00:24 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
		swap(*a, 'a');
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		swap(*a, 'a');
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
		swap(*a, 'a');
		rotate(a, 'a');
	}
}

void	sort_five(t_stack **a, t_stack **b)
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
		if ((*b)->value < (*a)->value)
			push(b, a, 'a');
		else if ((*b)->next == NULL)
			push(b, a, 'a');
		else
			reverse(a, 'a');
	}
	while ((*a)->value != min)
		swap(*a, 'a');
}

void	sort_radix(t_stack **a, t_stack **b)
{
	t_radix	radix;

	radix.max_num = find_max(*a);
	radix.max_bits = 0;
	radix.size = list_length(*a);
	while ((radix.max_num >> radix.max_bits) != 0)
		radix.max_bits++;
	radix.i = 0;
	while (radix.i < radix.max_bits)
	{
		radix.j = 0;
		while (radix.j < radix.size)
		{
			radix.num = (*a)->value;
			if (((radix.num >> radix.i) & 1) == 1)
				rotate(a, 'a');
			else
				push(a, b, 'b');
			radix.j++;
		}
		while (*b)
			push(b, a, 'a');
		radix.i++;
	}
}

void	sort(t_stack *a, t_stack *b, int argc)
{
	if (argc - 1 == 3)
		sort_three(&a);
	else if (argc - 1 == 5)
		sort_five(&a, &b);
	else
		sort_radix(&a, &b);
}
