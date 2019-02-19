/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:54:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 13:06:45 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_stradd(char *dst, char *src)
{
	int		dstlen;
	int		srclen;
	char	*str;

	if (!dst || !src)
		return ((char *)0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!(str = xmalloc(dstlen + srclen + 1)))
		return ((char *)0);
	ft_memcpy(str, dst, dstlen);
	ft_memcpy(str + dstlen, src, srclen);
	str[dstlen + srclen] = 0;
	free(dst);
	return (str);
}
