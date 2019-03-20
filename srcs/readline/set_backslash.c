/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_backslash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:02:15 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 11:02:16 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	set_backslash(const char *buf, size_t pos, int *backslash)
{
	if (buf[pos] == '\\')
	{
		if (pos == 0)
		{
			*backslash = 1;
			return ;
		}
		if (buf[pos - 1] == '\\')
		{
			if (*backslash == 1)
				*backslash = 0;
			else
				*backslash = 1;
			return ;
		}
		*backslash = 1;
	}
	else
		*backslash = 0;
}
