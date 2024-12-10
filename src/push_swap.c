/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:31:12 by arthur            #+#    #+#             */
/*   Updated: 2024/12/11 00:05:57 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*current;

	new = new_node(value);
	current = *stack;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

void	print_stack(t_stack *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		add_to_stack(&a, ft_atoi(argv[i]));
		i++;
	}
	sort(a, b, argc);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
