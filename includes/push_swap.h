/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:40:50 by arthur            #+#    #+#             */
/*   Updated: 2024/12/08 17:59:40 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;

}	t_stack;

void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse(t_stack **src);
void	rotate(t_stack **src);
void	push(t_stack **src, t_stack **dest);
void	ss(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
int		find_min(t_stack *stack);
int		find_second_min(t_stack *stack);
int 	list_length(t_stack *stack);
#endif