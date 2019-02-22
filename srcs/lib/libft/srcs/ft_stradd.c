/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:54:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *dst, char *src, int freesrc)
{
	int		dstlen;
	int		newlen;

	if (!dst || !src)
		return ((char *)0);
	dstlen = ft_strlen(dst);
	newlen = dstlen + ft_strlen(src) + 1;
	dst = xrealloc(dst, newlen, newlen);
	ft_memcpy(dst + dstlen, src, newlen - dstlen);
	if (freesrc)
		free(src);
	return (dst);
}
