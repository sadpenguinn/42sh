/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:39:35 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 11:29:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"
#include "term.h"
#include "shell.h"

t_line *init_line(void)
{
	t_line *line;

	line = (t_line *)xmalloc(sizeof(t_line));
	line->buf = (char *)xmalloc(sizeof(char) * BUF_DEFAULT + 1);
	line->size = BUF_DEFAULT;
	line->len = 0;
	line->cnt = 0;
	return (line);
}

t_matrix *init_matrix(void)
{
	t_matrix *matrix;

	matrix = xmalloc(sizeof(t_matrix));
	matrix->line = (t_line **)xmalloc(sizeof(t_line *) * MATRIX_DEFAULT);
	matrix->size = MATRIX_DEFAULT;
	matrix->len = 1;
	matrix->line[0] = init_line();
	matrix->cursor = (t_cursor *)xmalloc(sizeof(t_cursor));
	matrix->cursor->row = 0;
	matrix->cursor->col = 0;
	return (matrix);
}

int		main(void)
{
	int     ret;
	t_matrix *matrix;

	set_term();
	ret = 1;
	while (ret)
	{
		matrix = init_matrix();
		ret = ft_readline(matrix);
	}
	unset_term();
	return (0);
}
