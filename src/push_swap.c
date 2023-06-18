/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:09:30 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/18 19:46:38 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **str)
{
	t_int	*a;
	t_int	*b;
	int		i;

	if (c <= 2 || !parse_check(str))
		return (-1);
	i = 0;
	a = NULL;
	b = NULL;
	while (++i < c)
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(str[i])));
	index_values(a, INT_MAX);
	// if (is_sorted(a))
	// 	return (ft_printf("list is sorted :D\n"), 0);
	if (simple_sorting(&a, &b, c))
		return (0);
	radix_sort(&a, &b);
	// if (!is_sorted(a))
	// 	ft_printf("not sorted :(\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
}
