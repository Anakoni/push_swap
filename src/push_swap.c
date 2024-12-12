/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:31:12 by arthur            #+#    #+#             */
/*   Updated: 2024/12/12 07:29:27 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		swap(a, b, 'a');
	else if (size == 3)
		sort_three(a, b);
	else if (size > 3 && size < 6 && !is_sorted(*a))
		sort_five(a, b);
	else if (size > 5 && !is_sorted(*a))
	 	sort_stacks(a, b);
}

/* void	print_stack(t_stack *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 1;
	if (argc < 2)
		exit_error(NULL, NULL);
	a = NULL;
	b = NULL;
	if (!parse_input(argv, &a))
		exit_error(&a, &b);
	sort(&a, &b, stack_len(a));
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}
