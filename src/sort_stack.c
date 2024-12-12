/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:18:46 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 07:28:23 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clean_a(t_stack **a)
{
	t_stack	*target;

	target = get_smallest(*a);
	while (*a != target)
	{
		if (get_rotation_way(target, a))
			rotate(a, 'a');
		else if (!get_rotation_way(target, a))
			reverse(a, 'a');
		else
			break ;
	}
}

static t_move	*find_best_move(t_stack **src_stack, t_stack **dest_stack)
{
	t_stack	*temp_source;
	t_stack	*temp_target;
	t_move	*move;
	int		latest_cost;

	move = new_move(INT_MAX, NULL, NULL, NULL);
	temp_source = *src_stack;
	temp_target = *dest_stack;
	while (temp_source)
	{
		if (is_min(temp_source->value, *dest_stack))
			temp_target = get_biggest(*dest_stack);
		else
			temp_target = get_smaller(*dest_stack, temp_source->value);
		latest_cost = get_move_cost(src_stack,
				temp_source, dest_stack, temp_target);
		if (latest_cost < move->cost)
			move = update_move(latest_cost, temp_source, temp_target, move);
		temp_source = temp_source->next;
	}
	return (move);
}
	void	fiexecute_move(t_stack **a, t_stack **b
						, t_move *move)
{
	while (*a != move->source && *b != move->source)
	{
		if (get_rotation_way(move->source, a) == 1
			&& get_rotation_way(move->target, b) == 1)
			rr(a, b);
		else if (get_rotation_way(move->source, a) == 0
			&& get_rotation_way(move->target, b) == 0)
			rrr(a, b);
		else
			break ;
	}
	if (get_rotation_way(move->source, a) == 1)
		while (*a != move->source)
			rotate(a, 'a');
	else
		while (*a != move->source)
			reverse(a, 'a');
	if (get_rotation_way(move->target, b) == 1)
		while (*b != move->target)
			rotate(b, 'b');
	else
		while (*b != move->target)
			reverse(b, 'b');
	push(a, b, 'b');
	return ;
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	t_move	*move;

	push(a, b , 'b');
	push(a, b , 'b');
	while (*a)
	{
		move = find_best_move(a, b);
		fiexecute_move(a, b, move);
		free(move);
	}
	while (*b)
		push(b, a , 'a');
	clean_a(a);
}
