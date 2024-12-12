/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:40:50 by arthur            #+#    #+#             */
/*   Updated: 2024/12/11 01:07:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"

# ifndef ERROR
#  define ERROR 1
# endif

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
int		ft_atoi_check(char *str);
int		is_sorted(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	swap(t_stack *stack, char c);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
int		find_min(t_stack *stack);
int		find_second_min(t_stack *stack);
int		list_length(t_stack *stack);
void	sort_radix(t_stack **a, t_stack **b);
int		find_max(t_stack *stack);
long	ft_atol(char *str);
int		is_valid_number(const char *str);
int		has_duplicates(t_stack *stack);

#endif
