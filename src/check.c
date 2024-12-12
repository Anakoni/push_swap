/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:52:53 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 07:14:35 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(t_stack **a, t_stack **b)
{
	if (a == NULL || a != NULL)
		free_stack(a);
	if (b == NULL || b != NULL)
		free_stack(b);
	(write(2, RED, 8), write(2, "Error\n", 6), write(2, DEF_COLOR, 8));
	exit(1);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_bool	is_min(int n, t_stack *b)
{
	while (b)
	{
		if (b->value < n)
			return (FALSE);
		b = b->next;
	}
	return (TRUE);
}

t_bool	is_max(int n, t_stack *b)
{
	while (b)
	{
		if (b->value > n)
			return (FALSE);
		b = b->next;
	}
	return (TRUE);
}
