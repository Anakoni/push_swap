/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:31:12 by arthur            #+#    #+#             */
/*   Updated: 2024/12/08 17:55:46 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *new_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void add_to_stack(t_stack **stack, int value)
{
    t_stack *new = new_node(value);
    t_stack *current = *stack;

    if (!new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    while (current->next)
        current = current->next;
    current->next = new;
}

void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i = 1;

    if (argc < 2)
    {
        printf("Usage: %s [list of integers]\n", argv[0]);
        return (1);
    }
    while (i < argc)
    {
        add_to_stack(&a, atoi(argv[i]));
        i++;
    }
    printf("Initial stacks:\n");
    print_stack(a, "A");
    print_stack(b, "B");
    if (argc - 1 == 3)
        sort_three(&a);
    else if (argc - 1 == 5)
        sort_five(&a, &b);
    else
        printf("Tri pour d'autres tailles non implémenté.\n");
    printf("\nSorted stacks:\n");
    print_stack(a, "A");
    print_stack(b, "B");
    free_stack(&a);
    free_stack(&b);
    return (0);
}
