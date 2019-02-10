/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:51:42 by dmorgil           #+#    #+#             */
/*   Updated: 2019/01/17 16:47:48 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_strlen(str);
	if (len <= n)
		return (ft_strdup(str));
	if (!(new = (char *)malloc(n + 1)))
		return (0);
	ft_memcpy(new, str, n);
	new[n] = '\0';
	return (new);
}
