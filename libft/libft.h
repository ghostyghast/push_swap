/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:15:32 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/22 16:39:00 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_int
{
	int		num;
	t_int	*next;
}			t_int;

//libft
int		ft_atoi(const char *str);

int		ft_lstsize(t_int *lst);
t_int	*ft_lstnew(int num);
t_int	*ft_lstlast(t_int *lst);
void	ft_lstclear(t_int **lst);
void	ft_lstdelone(t_int *lst);
void	ft_lstadd_front(t_int **lst, t_int *new);
void	ft_lstadd_back(t_int **lst, t_int *new);

//ft_printf
int		ft_printf(const char *str, ...);
void	writer(const char *str, int *i);
void	ft_putchar(int c, int *i);
void	ft_putnbr(int nb, int *len);
void	ft_putunsigned(unsigned int nb, int *len);
void	ft_puthexa(unsigned int n, int *len);

#endif