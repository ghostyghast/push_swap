/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:24:27 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/06 18:48:16 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_alpha(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	check_dup(char **str, int i, int num)
{
	i++;
	while (str[i])
	{
		if (atoi(str[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	parse_check(char **str)
{
	int			i;
	long int	num;

	i = 0;
	while (str[++i])
	{
		num = ft_atoi(str[i]);
		if (!check_alpha(str[i]))
		{
			ft_putendl_fd("Invalid int", 2);
			return (0);
		}
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_putendl_fd("Int exceeds max/min int", 2);
			return (0);
		}
		if (!check_dup(str, i, num))
		{
			ft_putendl_fd("Duplicate int", 2);
			return (0);
		}
	}
	return (1);
}
