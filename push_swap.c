/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:09:30 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/25 12:24:48 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_int *stack)
{
	t_int	*a;

	a = stack;
	while (a->next)
	{
		ft_printf("%i ", a->num);
		a = a->next;
	}
	ft_printf("%i", a->num);
}

int	main(int c, char **str)
{
	t_int	*a;

	if (c == 1)
	{
		ft_printf("./push_swap\n");
		return (0);
	}
	a = parse_and_alloc(c, str);
	if (!a)
		return (0);
	print_stack(a);
	return (0);
}
