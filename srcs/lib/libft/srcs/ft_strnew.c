/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:49:29 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/28 02:16:23 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	size++;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return ((char *)0);
	i = 0;
	while (i < size)
		str[i++] = 0;
	return (str);
}
