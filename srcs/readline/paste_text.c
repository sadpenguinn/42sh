/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:20:11 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:20:56 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	paste_before(t_matrix *matrix)
{
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			get_buffer_content(), get_buffer_len());
	move_cursor_left(matrix);
}

void	paste_after(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_right(matrix);
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			get_buffer_content(), get_buffer_len());
	move_cursor_left(matrix);
}
