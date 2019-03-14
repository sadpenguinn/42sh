/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_conditions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:49:59 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:52:44 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		z_conditions(char *str)
{
	if ((!str) || (!str[0]))
		return (1);
	return (0);
}

int		equal_str_conditions(char *str1, char *str2)
{
	if (!ft_strcmp(str1, str2))
		return (1);
	return (0);
}

int		not_equal_str_conditions(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) != 0)
		return (1);
	return (0);
}
