/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:06:32 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/19 19:55:36 by amaligno         ###   ########.fr       */
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
	ft_printf("%i \n", a->num);
}

int	is_sorted(t_int *stack)
{
	stack = stack->next;
	while (stack)
	{
		if (stack->prev->num > stack->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_val(t_int *stack, int mode)
{
	int	num;

	num = stack->num;
	while (stack)
	{
		if (stack->num < num && !mode)
			num = stack->num;
		else if (stack->num < num)
			num = stack->num;
		stack = stack->next;
	}
	return (num);
}

void	push_to_top(t_int **head, int num, int size, char c)
{
	t_int	*ptr;
	int		i;

	i = 0;
	ptr = *head;
	while (i++ <= size && ptr->index != num)
		ptr = ptr->next;
	if ((size / 2) >= i)
	{
		while (i-- > 1)
			rotate(head, c);
	}
	else
	{
		while (i++ <= size)
			rev_rotate(head, c);
	}
}
