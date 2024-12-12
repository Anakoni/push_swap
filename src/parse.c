/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:28:18 by aperceva          #+#    #+#             */
/*   Updated: 2024/12/12 06:23:42 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (FALSE);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (FALSE);
	return (TRUE);
}
static t_bool	is_max_min(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (FALSE);
	return (TRUE);
}

static t_bool	no_dup(char **str, int i)
{
	int	j;

	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_bool	parse(int i, char **av, t_stack **stack_a)
{
	t_stack	*node;
	int		nb;
	int		j;

	j = i;
	while (av[i])
	{
		if (!is_valid(av[i]) || !is_max_min(av[i]) || !no_dup(av, j))
			return (FALSE);
		nb = ft_atoi(av[i]);
		node = new_node(nb);
		if (!node)
			return (FALSE);
		ft_stackadd_back(stack_a, node);
		i++;
	}
	return (TRUE);
}

t_bool	parse_input(char **argv, t_stack **a)
{
	int		i;
	char	**age;
	t_bool	var;

	i = 1;
	age = argv;
	var = parse(i, age, a);
	return (var);
}
