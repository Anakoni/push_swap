/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 06:52:40 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 07:24:03 by aperceva         ###   ########.fr       */
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
t_move	*new_move(int cost, t_stack *source, t_stack *target, t_move *move)
{
	move = malloc(sizeof(t_move));
	move->cost = cost;
	move->target = target;
	move->source = source;
	return (move);
}

t_move	*update_move(int cost, t_stack *source, t_stack *target, t_move *move)
{
	move->cost = cost;
	move->target = target;
	move->source = source;
	return (move);
}
