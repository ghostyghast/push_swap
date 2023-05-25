/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:24:27 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/25 13:14:32 by amaligno         ###   ########.fr       */
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

int	check_dup_and_int(char **str, int args)
{
	int			i;
	int			y;
	long int	temp;

	i = 1;
	if (!check_alpha(str[i]))
		return (0);
	while (++i < args)
	{
		y = 0;
		while (i > ++y)
		{
			temp = ft_atoi(str[y]);
			if ((ft_atoi(str[y]) > INT_MAX || ft_atoi(str[y]) < INT_MIN) || !check_alpha(str[i]))
			{
				ft_putendl_fd("Error : invalid integer", 2);
				return (0);
			}
			if (ft_atoi(str[i]) == temp)
			{
				ft_putendl_fd("Error : Duplicate number", 2);
				return (0);
			}
		}
	}
	return (1);
}

t_int	*parse_and_alloc(int c, char **str)
{
	int		i;
	t_int	*lst;

	i = 0;
	if (!check_dup_and_int(str, c))
		return (NULL);
	while (++i < c)
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(str[i])));
	return (lst);
}
