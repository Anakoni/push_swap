/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:40:50 by arthur            #+#    #+#             */
/*   Updated: 2024/12/11 00:14:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;

}	t_stack;

typedef struct s_radix
{
	int	max_num;
	int	num;
	int	max_bits;
	int	size;
	int	i;
	int	j;
}	t_radix;

void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse(t_stack **src, char c);
void	rotate(t_stack **src, char c);
void	push(t_stack **src, t_stack **dest, char c);
void	sort(t_stack *a, t_stack *b, int argc);
void	ss(t_stack *a, t_stack *b);
void	swap(t_stack *stack, char c);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
int		find_min(t_stack *stack);
int		find_second_min(t_stack *stack);
int		list_length(t_stack *stack);
void	sort_radix(t_stack **a, t_stack **b);
int		find_max(t_stack *stack);

#endif
