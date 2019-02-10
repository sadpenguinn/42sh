/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:44:39 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/21 18:45:58 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *s)
{
	char *res;

	res = s;
	while (*s)
	{
		if (ft_isupper(*s))
			*s = ft_tolower(*s);
		s++;
	}
	return (res);
}
