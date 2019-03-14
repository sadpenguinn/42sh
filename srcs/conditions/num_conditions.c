/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:50:52 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:52:48 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		eq_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) == ft_atoi(str2))
		return (1);
	return (0);
}

int		ne_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) != ft_atoi(str2))
		return (1);
	return (0);
}

int		ge_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) >= ft_atoi(str2))
		return (1);
	return (0);
}

int		lt_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) < ft_atoi(str2))
		return (1);
	return (0);
}

int		le_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) <= ft_atoi(str2))
		return (1);
	return (0);
}
