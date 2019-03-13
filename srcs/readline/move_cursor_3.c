/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:18:30 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:18:49 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	move_cursor_next_word(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_next_word(matrix);
	return (1);
}

int	move_cursor_begin_word(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_begin_word(matrix);
	return (1);
}

int	move_cursor_end_word(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_end_word(matrix);
	return (1);
}

int move_cursor_next_char(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_next_char(matrix);
	return (1);
}

int move_cursor_back_char(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_back_char(matrix);
	return (1);
}
