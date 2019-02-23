/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:46:45 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (haystack[i] == needle[i] && len - i)
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			i++;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
