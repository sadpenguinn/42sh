/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:44:55 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 20:09:54 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_numeric(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}
