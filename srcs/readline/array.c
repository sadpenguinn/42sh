/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:09:46 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 14:26:45 by sitlcead         ###   ########.fr       */
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
	arr->buf = (char *)xmalloc(ARRAY_DEFAULT_SIZE);
	arr->len = 0;
	arr->size = ARRAY_DEFAULT_SIZE;
}

void		array_add(const char *str, unsigned int len)
{
	if (str == NULL)
		return;
	if (arr == NULL)
		init_array();
	if (len == 0)
		return ;
	if (arr->len + len > arr->size)
	{
		arr->buf = (char *)xrealloc(arr->buf, arr->size * FACTOR + len, arr->size);
		arr->size = arr->size * FACTOR + len;
	}
	memcpy(arr->buf + arr->len, str, len);
	arr->len += len;
}

char		*array_to_string(void)
{
	char	*str;

	str = (char *)xmalloc(arr->len + 1);
	memmove(str, arr->buf, arr->len);
	free(arr->buf);
	free(arr);
	arr = NULL;
	return (str);
}

void		array_flush(void)
{
	write(1, arr->buf, arr->len);
	free(arr->buf);
	free(arr);
	arr = NULL;
}
