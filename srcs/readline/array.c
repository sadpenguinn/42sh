/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:40:42 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 09:14:41 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <string.h>

static t_array	*arr;

void	array_add(const char *str, int len)
{
	if (arr == NULL)
	{
		arr = (t_array *)xmalloc(sizeof(t_array));
		arr->buf = (char *)xmalloc
	}
}
