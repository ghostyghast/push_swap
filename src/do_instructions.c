/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:56:02 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/18 20:17:44 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	instructions(t_int **stack_a, t_int **stack_b, char *str)
{
	ft_printf("str : %s]", str);
	if (!ft_strcmp(str, "pa\n"))
		push(stack_b, stack_a, 'a');
	else if (!ft_strcmp(str, "pb\n"))
		push(stack_a, stack_b, 'a');
	else if (!ft_strcmp(str, str))
	{
		ft_printf("hi\n");	
		swap(stack_a, 'a');
	}
	// else if (!ft_strcmp(str, "sb\n"))
	// 	swap(stack_b, 'b');
	// else if (!ft_strcmp(str, "ra\n"))
	// 	rotate(stack_a, 'a');
	// else if (!ft_strcmp(str, "rb\n"))
	// 	rotate(stack_b, 'b');
	// else if (!ft_strcmp(str, "rr\n"))
	// 	dual_action(stack_a, stack_b, rotate, 'r');
	// else if (!ft_strcmp(str, "ss\n"))
	// 	dual_action(stack_a, stack_b, swap, 's');
	// else if (!ft_strcmp(str, "rra\n"))
	// 	rev_rotate(stack_a, 'a');
	// else if (!ft_strcmp(str, "rrb\n"))
	// 	rev_rotate(stack_b, 'b');
	// else if (!ft_strcmp(str, "rrr\n"))
	// 	dual_action(stack_a, stack_b, rotate, 'r');
	else
		return (0);
	return (1);
}

void	do_instructions(t_int **stack_a, t_int **stack_b)
{
	char	*str;
	str = get_next_line(0);
	ft_printf("str : %s", str);	
	while (str)
	{
		if (!ft_strcmp(str, "\n"))
		{
			ft_printf("only nl\n");	
			free(str);
			break ;
		}
		if (!instructions(stack_a, stack_b, str))
		{
			ft_printf("instruct \n");		
			free(str);
			break ;
		}
		ft_printf("loop str : %s", str);
		free(str);
		str = get_next_line(0);
	}
	print_stack(*stack_a);
	if (is_sorted(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
