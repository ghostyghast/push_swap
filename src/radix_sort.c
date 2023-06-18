/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:54:27 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/16 16:20:06 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int size)
{
	int	i;

	i = 0;
	while ((size >> i) != 0)
		i++;
	return (i);
}

void	radix_sort(t_int **stack_a, t_int **stack_b)
{
	int		max_bits;
	int		bits;
	int		size;
	int		i;

	i = 0;
	bits = 0;
	size = ft_lstsize(*stack_a);
	max_bits = count_bits(size);
	while (bits < max_bits)
	{
		i = 0;
		while (i++ < size)
		{
			if (((*stack_a)->index >> bits) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		bits++;
	}
}
