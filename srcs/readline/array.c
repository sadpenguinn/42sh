/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:40:42 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 11:27:38 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <string.h>
#include "shell.h"
#include <unistd.h>

static t_array	*arr;

static void	init_array(void)
{
	arr = (t_array *)xmalloc(sizeof(t_array));
	arr->buf = (char *)xmalloc(ARRAY_SIZE);
	arr->len = 0;
	arr->size = ARRAY_SIZE;
}

void	array_add(const char *str, unsigned int len)
{
	if (str == NULL)
		return ;
	if (arr == NULL)
		init_array();
	if (len == 0)
		len = strlen(str);
	if (arr->len + len > arr->size)
	{
		arr->buf = (char *)xrealloc(arr->buf, arr->size * FACTOR + len, arr->size);
		arr->size = arr->size * FACTOR + len;
	}
	memcpy(arr->buf + arr->len, str, len);
	arr->len += len;
}

void	array_flush(int fd)
{
	write(fd, arr->buf, arr->len);
	free(arr->buf);
	free(arr);
	arr = NULL;
}
