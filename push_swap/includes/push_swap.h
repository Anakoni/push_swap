/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:40:50 by arthur            #+#    #+#             */
/*   Updated: 2024/12/06 21:48:49 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stacka
{
    int value;
    struct s_stacka *next;
    
}   t_stacka;

typedef     struct s_stackb
{
    int     value;
    struct  s_stackb *next;
    
}   t_stackb;

#endif