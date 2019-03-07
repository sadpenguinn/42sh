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
	while (ret == -1)
	{
		dup2(-1, 0);
		print_lines(g_history->cur_matrix);
		write(1, "\n", 1);
		print_prompt();
		matrix_del(&g_history->cur_matrix);
		matrix_del(&g_history->matrix[g_history->len - 1]);
		g_history->cur_matrix = matrix_init();
		matrix_create_line(g_history->cur_matrix, 0);
		g_history->matrix[g_history->len - 1] = matrix_dup(g_history->cur_matrix);
		print_default(g_history->cur_matrix);
		ret = read(0, &c, size);
	}
	return (c);
}
