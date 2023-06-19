/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:56:02 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/19 19:55:18 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	instructions(t_int **stack_a, t_int **stack_b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push(stack_b, stack_a, 'a');
	else if (!ft_strcmp(str, "pb\n"))
		push(stack_a, stack_b, 'b');
	else if (!ft_strcmp(str, "sa\n"))
		swap(stack_a, 'a');
	else if (!ft_strcmp(str, "sb\n"))
		swap(stack_b, 'b');
	else if (!ft_strcmp(str, "ra\n"))
		rotate(stack_a, 'a');
	else if (!ft_strcmp(str, "rb\n"))
		rotate(stack_b, 'b');
	else if (!ft_strcmp(str, "rr\n"))
		dual_action(stack_a, stack_b, rotate, 'r');
	else if (!ft_strcmp(str, "ss\n"))
		dual_action(stack_a, stack_b, swap, 's');
	else if (!ft_strcmp(str, "rra\n"))
		rev_rotate(stack_a, 'a');
	else if (!ft_strcmp(str, "rrb\n"))
		rev_rotate(stack_b, 'b');
	else if (!ft_strcmp(str, "rrr\n"))
		dual_action(stack_a, stack_b, rotate, 'r');
	else
		return (ft_putendl_fd("Error", 2), 0);
	return (1);
}

void	do_instructions(t_int **stack_a, t_int **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!ft_strcmp(str, "\n"))
		{
			free(str);
			break ;
		}
		if (!instructions(stack_a, stack_b, str))
		{
			free(str);
			exit(0);
		}
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
