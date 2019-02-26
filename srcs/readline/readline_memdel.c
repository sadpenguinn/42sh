/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_memdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:04:09 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 17:04:53 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	line_free(t_line *line)
{
	free(line->buf);
	free(line);
}

void	line_del(t_line **line)
{
	line_free(*line);
	*line = NULL;
}

void	matrix_free(t_matrix *matrix)
{
	int i;

	free(matrix->cursor);
	i = 0;
	while (i < matrix->len)
		line_free(matrix->lines[i++]);
	free(matrix->lines);
	free(matrix);
}

void	matrix_del(t_matrix **matrix)
{
	matrix_free(*matrix);
	*matrix = NULL;
}
