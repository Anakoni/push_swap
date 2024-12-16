/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 06:39:42 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/16 12:53:24 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **a, t_stack **b, char c)
{
	int	tmp;

	if (!a || !*a || !(*a)->next)
		exit_error(a, b);
	if ((*a)->value && (*a)->next->value)
	{
		tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
	}
	if (!c)
		return ;
	ft_printf("s%c\n", c);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(&a, &b, 0);
	swap(&a, &b, 0);
	ft_printf("%s\n", "ss");
}

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (!c)
		return ;
	ft_printf("p%c\n", c);
}

void	rotate(t_stack **src, char c)
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
	if (!c)
		return ;
	ft_printf("r%c\n", c);
}

void	reverse(t_stack **src, char c)
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
	if (!c)
		return ;
	ft_printf("rr%c\n", c);
}
