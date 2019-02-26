/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:50:24 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:50:25 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_line		*init_line(void)
{
	t_line	*line;

	line = (t_line *)xmalloc(sizeof(t_line));
	line->buf = (char *)xmalloc(sizeof(char) * BUF_DEFAULT_SIZE + 1);
	line->size = BUF_DEFAULT_SIZE;
	line->len = 0;
	line->symbols = 0;
	return (line);
}

t_matrix	*init_matrix(void)
{
	t_matrix	*matrix;

	matrix = xmalloc(sizeof(t_matrix));
	matrix->lines = (t_line **)xmalloc(sizeof(t_line *) * MATRIX_DEFAULT_SIZE);
	matrix->size = MATRIX_DEFAULT_SIZE;
	matrix->len = 1;
	matrix->lines[0] = init_line();
	matrix->cursor = (t_cursor *)xmalloc(sizeof(t_cursor));
	matrix->cursor->row = 0;
	matrix->cursor->col = 0;
	matrix->last_offset = 0;
	matrix->left_limit = 0;
	matrix->right_limit = 0;
	return (matrix);
}
