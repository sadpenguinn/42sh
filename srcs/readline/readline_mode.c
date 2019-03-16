/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:03:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 20:37:12 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

static int	are_default_readline_mode_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_B || c == LEFT)
		return (move_cursor_left(matrix));
	if (c == CTRL_F || c == RIGHT)
		return (move_cursor_right(matrix));
	if (c == HOME1 || c == HOME2)
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2)
		return (move_cursor_end(matrix));
	if (c == DEL)
		return (del(matrix));
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == UP)
		return (move_cursor_up(matrix));
	if (c == DOWN)
		return (move_cursor_down(matrix));
	if (c == CTRL_H)
		return (move_cursor_begin_word(matrix));
	if (c == CTRL_L)
		return (move_cursor_end_word(matrix));
	if (c == BS)
		return (back_space(matrix));
	return (0);
}

static int	ctrl_t_handling(t_matrix *matrix)
{
	back_space(matrix);
	move_cursor_right(matrix);
	paste_before(matrix);
	return (move_cursor_right(matrix));
}

int			readline_mode(t_uchar c)
{
	char		str[sizeof(t_uchar)];
	t_matrix	*matrix;

	if (c == CTRL_R)
	{
		g_search_mode = 1;
		return (1);
	}
	matrix = g_history->matrix[g_history->cur];
	if (c == CTRL__)
		return (undo(matrix));
	if (are_default_readline_mode_shortcuts(matrix, c))
		return (1);
	if (c == CTRL_T)
		return (ctrl_t_handling(matrix));
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	ft_memset(str, 0, sizeof(t_uchar));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			str, symbol_to_string(c, str));
	return (1);
}
