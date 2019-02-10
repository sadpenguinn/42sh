/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:57:51 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/26 14:51:25 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcpy(char *dest, const char *src)
{
	size_t len;

	len = ft_strlen(src);
	ft_memcpy(dest, src, len + 1);
	return (len);
}
