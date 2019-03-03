/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:03:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 05:01:16 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	readline_mode(t_matrix *matrix, t_uchar c)
{
	char	str[8];

	memset(str, 0, 8);
	if (c == BS)
		return (back_space(matrix));
	if (c == CTRL_B)
		return (move_cursor_left(matrix));
	if (c == CTRL_F)
		return (move_cursor_right(matrix));
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	matrix_string_insert(matrix, matrix->cursor,
			str, symbol_to_string(matrix, c, str));
	return (1);
}
