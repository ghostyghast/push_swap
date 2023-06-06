/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:04 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/06 21:45:07 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int		parse_check(char **str);

//the push swap moves
void	push(t_int **src_stack, t_int **dst_stack, char c);
void	swap(t_int **stack, char c);
void	rotate(t_int **stack, char c);
void	rev_rotate(t_int **stack, char c);
void	dual_action(t_int **a, t_int **b, void (*f)(t_int **, char), char c);
void	print_stack(t_int *stack);
#endif