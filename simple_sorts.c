/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:02:27 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/14 19:05:03 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_int **lst)
{
	t_int	*stack;

	if (is_sorted(*lst))
		return ;
	stack = (*lst)->next;
	if (stack->prev->index > stack->index)
	{
		if ((stack->prev->index > stack->next->index)
			&& (stack->index < stack->next->index))
			rotate(lst, 'a');
		else if (stack->index < stack->next->index)
			swap(lst, 'a');
		else
		{
			swap(lst, 'a');
			rev_rotate(lst, 'a');
		}
	}
	else if (stack->next->index < stack->prev->index)
		rev_rotate(lst, 'a');
	else
	{
		swap(lst, 'a');
		rotate(lst, 'a');
	}
}

void	four_sort(t_int **stack_a, t_int **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	push_to_top(stack_a, 1, ft_lstsize(*stack_a), 'a');
	push(stack_a, stack_b, 'b');
	three_sort(stack_a);
	push(stack_b, stack_a, 'a');
}

void	five_sort(t_int **stack_a, t_int **stack_b)
{	
	if (is_sorted(*stack_a))
		return ;
	push_to_top(stack_a, 1, ft_lstsize(*stack_a), 'a');
	push(stack_a, stack_b, 'b');
	push_to_top(stack_a, 2, ft_lstsize(*stack_a), 'a');
	push(stack_a, stack_b, 'b');
	three_sort(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}

int	simple_sorting(t_int **a, t_int **b, int c)
{
	if (c == 3 && (*a)->num > (*a)->next->num)
		return (swap(a, 'a'), 1);
	else if (c == 4)
		return (three_sort(a), 1);
	else if (c == 5)
		return (four_sort(a, b), 1);
	else if (c == 6)
		return (five_sort(a, b), 1);
	return (0);
}
