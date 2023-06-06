/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:09:30 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/06 21:55:14 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_int *stack)
{
	t_int	*a;

	if (!stack)
	{
		ft_printf("(null)\n");
		return ;
	}
	a = stack;
	while (a->next)
	{
		ft_printf("%i ", a->num);
		a = a->next;
	}
	ft_printf("%i\n", a->num);
}

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
	return (0);
}
