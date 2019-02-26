/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:09:46 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/26 16:45:57 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <string.h>
#include "shell.h"
#include <unistd.h>

static t_array	*g_arr;

static void	init_array(void)
{
	g_arr = (t_array *)xmalloc(sizeof(t_array));
	g_arr->buf = (char *)xmalloc(ARRAY_DEFAULT_SIZE);
	g_arr->len = 0;
	g_arr->size = ARRAY_DEFAULT_SIZE;
}

void		array_add(const char *str, size_t len)
{
	if (str == NULL)
		return ;
	if (g_arr == NULL)
		init_array();
	if (len == 0)
		return ;
	if (g_arr->len + len > g_arr->size)
	{
		g_arr->buf = (char *)xrealloc(g_arr->buf,
				g_arr->size * FACTOR + len, g_arr->size);
		g_arr->size = g_arr->size * FACTOR + len;
	}
	memcpy(g_arr->buf + g_arr->len, str, len);
	g_arr->len += len;
}

char		*array_to_string(void)
{
	char	*str;

	str = (char *)xmalloc(g_arr->len + 1);
	memmove(str, g_arr->buf, g_arr->len);
	free(g_arr->buf);
	free(g_arr);
	g_arr = NULL;
	return (str);
}

void		array_flush(void)
{
	write(1, g_arr->buf, g_arr->len);
	free(g_arr->buf);
	free(g_arr);
	g_arr = NULL;
}
