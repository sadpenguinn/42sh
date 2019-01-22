/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:45:37 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/26 15:06:48 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || !(str = (char *)malloc(sizeof(char) * (len + 1))))
		return ((char *)0);
	ft_memcpy(str, s + start, len);
	str[len] = 0;
	return (str);
}
