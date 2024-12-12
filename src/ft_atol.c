/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 06:01:08 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 06:01:15 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	fin;

	i = 0;
	sign = 1;
	fin = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		fin = fin * 10 + (str[i] - '0');
		i++;
	}
	return (sign * fin);
}
