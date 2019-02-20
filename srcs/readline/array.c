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

/*arrays save char strings(with no size limit if ARR_LEN_LIMIT != 0) and flush them(when need) to stdout*/

static t_array	*arr;

static void	init_array(void)
{
	arr = (t_array *)xmalloc(sizeof(t_array));
	arr->buf = (char *)xmalloc(DEFAULT_SIZE);
	arr->len = 0;
	arr->size = DEFAULT_SIZE;
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
	if (ARR_LEN_LIMIT && arr->len > ARR_LEN_LIMIT)
		array_flush();
}

char *array_to_string(void)
{
	char *str;

	str = (char *)xmalloc(arr->len + 1);
	memmove(str, arr->buf, arr->len);
	free(arr->buf);
	free(arr);
	arr = NULL;
	return (str);
}

void	array_flush(void)
{
	write(1, arr->buf, arr->len);
	free(arr->buf);
	free(arr);
	arr = NULL;
}
