/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:40:50 by arthur            #+#    #+#             */
/*   Updated: 2024/12/12 07:28:05 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libs/libft/libft.h"

# ifndef ERROR
#  define ERROR 1
# endif

# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define DEF_COLOR "\033[0;39m"



typedef int	t_bool;

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;

}	t_stack;

typedef struct s_move
{
	t_stack	*source;
	t_stack	*target;
	int		cost;
}	t_move;

t_stack	*new_node(int nb);
t_stack	*get_biggest(t_stack *stack);
t_stack	*get_smallest(t_stack *stack);
t_stack	*get_smaller(t_stack *stack, int target);
t_stack	*get_bigger(t_stack *stack, int target);
t_bool	parse_input(char **argv, t_stack **a);
t_bool	is_min(int n, t_stack *b);
t_bool	is_max(int n, t_stack *b);
t_bool	get_rotation_way(t_stack *target, t_stack **stack);
t_move	*new_move(int cost, t_stack *source, t_stack *target, t_move *move);
t_move	*update_move(int cost, t_stack *source, t_stack *target, t_move *move);
long	ft_atol(char *str);
int		is_sorted(t_stack *a);
int		stack_len(t_stack *stack);
int		stack_index(t_stack *stack, int value);
int	get_move_cost(t_stack **a, t_stack *source, t_stack **b, t_stack *target);
void	free_stack(t_stack **stack);
void	exit_error(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse(t_stack **src, char c);
void	rotate(t_stack **src, char c);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack **src, t_stack **dest, char c);
void	swap(t_stack **a, t_stack **b,char c);
void	sort_three(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
void	ft_stackadd(t_stack **a, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);

#endif
