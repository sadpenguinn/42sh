/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:21:08 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/22 00:21:08 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void    matrix_create_line(t_matrix *matrix, int row)
{
	if (matrix->len == matrix->size)
		matrix_resize(matrix, matrix->size * RATIO, matrix->size);
	if (row < matrix->len)
		memmove(matrix->lines + row + 1, matrix->lines + row,
				(matrix->len - row) * sizeof(t_line *));
	matrix->lines[row] = init_line();
	matrix->len++;
	matrix->cursor->row	 = row;
	matrix->cursor->col = 0;
}