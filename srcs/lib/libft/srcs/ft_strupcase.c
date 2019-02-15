/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:40:50 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/21 18:46:11 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *s)
{
	char *res;

	res = s;
	while (*s)
	{
		if (ft_islower(*s))
			*s = ft_toupper(*s);
		s++;
	}
	return (res);
}