/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:15:05 by arthur            #+#    #+#             */
/*   Updated: 2024/12/07 19:15:45 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->value && stack->next->value)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*current;

	if (*src == NULL || (*src)->next == NULL)
		return ;
	first = *src;
	current = *src;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	*src = first->next;
	first->next = NULL;
}

void	reverse(t_stack **src)
{
	t_stack	*prev;
	t_stack	*current;

	if (*src == NULL || (*src)->next == NULL)
		return ;
	current = *src;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *src;
	*src = current;
}