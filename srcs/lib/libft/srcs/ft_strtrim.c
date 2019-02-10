/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:25:27 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/20 21:39:24 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return ((char *)0);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	len = 0;
	i = 0;
	while (s[i++])
		len++;
	i--;
	while (len-- && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || !s[i]))
		i--;
	len += 2;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == (char *)0)
		return ((char *)0);
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = 0;
	return (str);
}
