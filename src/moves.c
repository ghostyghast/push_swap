/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:32:36 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/12 13:11:14 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	push function: it takes the adress of last node of src stack, 
//	and adds it to last node of dst stack
void	push(t_int **src_stack, t_int **dst_stack, char c)
{
	t_int	*src_head;

	if (!*src_stack)
		return ;
	src_head = *src_stack;
	if (src_head->next)
	{
		src_head->next->prev = NULL;
		*src_stack = src_head->next;
		src_head->next = NULL;
	}
	else
		*src_stack = NULL;
	ft_lstadd_front(dst_stack, src_head);
	ft_printf("p%c\n", c);
}

//swap function, it switches first two values of first two nodes of stack
void	swap(t_int **stack, char c)
{
	int		num;
	t_int	*head;

	if (!stack || ft_lstsize(*stack) <= 1)
		return ;
	head = *stack;
	num = head->num;
	head->num = head->next->num;
	head->next->num = num;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	else if (c == 's')
		ft_printf("ss\n", c);
}

void	rotate(t_int **stack, char c)
{
	t_int	*temp;

	if (!stack || ft_lstsize(*stack) <= 1)
		return ;
	temp = *stack;
	temp->next->prev = NULL;
	*stack = temp->next;
	ft_lstadd_back(stack, temp);
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	else if (c == 'r')
		ft_printf("rr\n", c);
}

void	rev_rotate(t_int **stack, char c)
{
	t_int	*temp;

	if (!stack || ft_lstsize(*stack) <= 1)
		return ;
	temp = ft_lstlast(*stack);
	temp->prev->next = NULL;
	ft_lstadd_front(stack, temp);
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

void	dual_action(t_int **a, t_int **b, void (*f)(t_int **, char), char c)
{
	if (c == 's')
	{
		f(a, 's');
		f(b, 0);
	}
	else if (c == 'r')
	{
		f(a, 'r');
		f(b, 0);
	}
}
