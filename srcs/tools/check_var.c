/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:36:36 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/28 21:10:21 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		check_var(char *var)
{
	int	st_start;
	int	st_end;

	st_start = 1;
	st_end = 0;
	while (*var)
	{
		if (st_start && (ft_isalpha(*var) || *var == '_'))
		{
			st_start = 0;
			st_end = 1;
		}
		else if (st_end && (ft_isalpha(*var) || ft_isdigit(*var) || *var == '_'))
			st_end = 1;
		else
			return (0);
		var++;
	}
	if (!*var)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%d\n", check_var(av[1]));
	return (0);
}
