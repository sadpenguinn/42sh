/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:05:38 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 18:29:22 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

size_t	symbol_to_string(t_uchar c, char *str)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = get_utf_offset_right(*((char *)&c));
	while (i <= n)
	{
		str[i] = (char)((c >> (i * 8)) & 0xFF);
		i++;
	}
	return (i);
}
