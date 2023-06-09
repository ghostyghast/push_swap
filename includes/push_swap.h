/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:04 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/18 19:50:09 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "libft.h"

int		parse_check(char **str);
void	radix_sort(t_int **stack_a, t_int **stack_b);

//utils
int		is_sorted(t_int *stack);
int		get_val(t_int *stack, int mode); //if mode is 0 get min, else get max
void	print_stack(t_int *stack);
void	index_values(t_int *stack, int val);
void	push_to_top(t_int **head, int num, int size, char c);

//simple sorts
int		simple_sorting(t_int **a, t_int **b, int c);
void	three_sort(t_int **stack_a);
void	four_sort(t_int **stack_a, t_int **stack_b);
void	five_sort(t_int **stack_a, t_int **stack_b);

//the push swap moves
void	push(t_int **src_stack, t_int **dst_stack, char c);
void	swap(t_int **stack, char c);
void	rotate(t_int **stack, char c);
void	rev_rotate(t_int **stack, char c);
void	dual_action(t_int **a, t_int **b, void (*f)(t_int **, char), char c);

//push_swap bonus checker
void	do_instructions(t_int **stack_a, t_int **stack_b);
#endif