/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:54 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_lowercase(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (!ft_islower(*s++))
			return (0);
	return (1);
}
