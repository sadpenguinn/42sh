/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:49:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:50:13 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>
#include <fcntl.h>

t_uchar		get_next_symbol(size_t size)
{
	t_uchar	c;
	int		ret;

	c = 0;
	if (size > sizeof(t_uchar))
		size = sizeof(t_uchar);
	ret = read(0, &c, size);
	if (ret == -1 && g_heredoc)
		return ('\n');
	while (ret == -1)
	{
		print_end(g_history->matrix[g_history->cur]);
		print_prompt();
		g_history->cur = g_history->len - 1;
		matrix_del(&g_history->matrix[g_history->cur]);
		g_history->matrix[g_history->cur] = matrix_init();
		matrix_create_line(g_history->matrix[g_history->cur], 0);
		print_default(g_history->matrix[g_history->cur]);
		ret = read(0, &c, size);
	}
	return (c);
}
