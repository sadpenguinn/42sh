/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:24:10 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:24:31 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

char	*get_buffer_content(void)
{
	return (g_history->buffer->buf);
}

size_t	get_buffer_len(void)
{
	return (g_history->buffer->len);
}

void	buffer_del(void)
{
	free(g_history->buffer->buf);
	g_history->buffer->len = 0;
	g_history->buffer->buf = NULL;
}

void	buffer_add(const char *str, size_t size)
{
	buffer_del();
	g_history->buffer->buf = (char *)xmalloc(sizeof(char) * size);
	g_history->buffer->len = size;
	ft_memcpy(g_history->buffer->buf, str, size);
}
