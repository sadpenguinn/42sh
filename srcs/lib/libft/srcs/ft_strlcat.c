/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:51:53 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/20 20:17:49 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	while (dst[i])
		i++;
	len += (i < size) ? i : size;
	while (size && *src && i < size - 1)
		dst[i++] = *src++;
	if (i < size)
		dst[i] = 0;
	return (len);
}
