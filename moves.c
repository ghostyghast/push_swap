/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:32:36 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/23 15:40:24 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_int *src_stack, t_int *dst_stack)
{
	t_int	*src_last;
	t_int	*dst_last;
	int		*lst_size;

	if (!src_stack->num)
		return ;
	src_last = ft_lstlast(src_stack);
	dst_last = ft_lstlast(dst_stack);
	lst_size = ft_lstsize(dst_stack);
	src_last->next = dst_last;
	while (--lst_size != 2)
		dst_last = dst_stack->next;
	dst_last->next = NULL;
}

void	swap(t_int *stack)
{
	t_int	*b4_last;
	int		num;
	int		size;

	b4_last = stack;
	size = ft_lstsize;
	if (!stack->num || size <= 1)
		return ;
	while (size-- != 2)
		b4_last = b4_last->next;
	num = ft_lstlast(stack)->num;
	ft_lstlast(stack)->num = b4_last->num;
	b4_last->num = num;
}

void	rotate(t_int *stack)
{
	int	num;

	num = stack->num;
	stack->num = ft_lstlast(stack)->num;
	ft_lstlast(stack)->num = num;
}

void	rev_rotate(t_int *stack)
{
	int	num;

	num = ft_lstlast(stack)->num;
	ft_lstlast(stack)->num = stack->num;
	stack->num = num;
}

void	dual_rotate(t_int *stack_a, t_int *stack_b, void (*f)(t_int *))
{
	f(stack_a);
	f(stack_b);
}
