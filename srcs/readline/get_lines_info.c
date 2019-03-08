/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:50:09 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:52:06 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

size_t	get_lines_offset(size_t len)
{
	size_t i;

	if (len == 1 || len == 0)
		return (0);
	i = 0;
	while (len)
	{
		i++;
		len /= 10;
	}
	return (i);
}

size_t	get_lines_prompt_len(size_t max)
{
	return (2 + get_lines_offset(max));
}
