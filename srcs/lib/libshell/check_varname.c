/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_varname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:36:36 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/09 20:50:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshell.h"

/*
 * Function to check name of the variable for correctness
 */

int		check_varname(char *var)
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
		else if (st_end && (ft_isalpha(*var) || ft_isdigit(*var)
														|| *var == '_'))
			st_end = 1;
		else
			return (0);
		var++;
	}
	if (!*var)
		return (1);
	return (0);
}
