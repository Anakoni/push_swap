/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:08:23 by arthur            #+#    #+#             */
/*   Updated: 2024/12/11 01:05:49 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi_check(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT32_MIN || num > INT32_MAX)
		return (0);
	return (1);
}
