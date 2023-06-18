/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:56:33 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/18 20:16:54 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	ft_printf("out s2 str : %s", s2);
	ft_printf("out s1 : [%c]\n s2 : [%c]\n", *s1, s2[0]);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			ft_printf("in s1 : [%c]\n s2 : [%c]\n", *s1, *s2);
			// ft_printf("in cmp, s1 : [%s]s2 : [%s]\n", &s1[0], &s2[0]);
			return (1);
		}
		if (*(++s1) == '\0' && *(++s2) == '\0')
			return (0);
	}
	return (0);
}

// int	main(int argc, char  **str)
// {	
// 	if (!strcmp("h", "h"))
// 		printf("same\n");
// 	else
// 		printf("diff\n");
// }