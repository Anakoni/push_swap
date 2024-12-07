/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:31:12 by arthur            #+#    #+#             */
/*   Updated: 2024/12/07 16:43:08 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacka *newNode(int value)
{
    t_stacka *new_node = (t_stacka*)malloc(sizeof(t_stacka));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

void addNode(t_stacka** head, t_stacka *new)
{
    
    t_stacka *tmp;

    if (!*head)
    {
        *head = new;
        return ;
    }
    tmp = *head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = NULL;
}

void display(t_stacka* head) {
    t_stacka* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    t_stacka* head = NULL;
    
    t_stacka *new = newNode(10);
    addNode(&head, new);
    new = newNode(20);
    addNode(&head, new);
    display(head);
    
    return 0;
}
