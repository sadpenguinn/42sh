#include "readline.h"
#include <stdio.h>

int insert_mode(t_matrix *matrix, t_uchar c)
{
	char	str[sizeof(t_uchar)];

	memset(str, 0, sizeof(t_uchar));

	if (check_default_shortcuts(matrix, c))
		return (1);
	if (c == BS)
		return (back_space(matrix));
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (move_cursor_left(matrix));
	}
	matrix_string_insert(matrix, matrix->cursor,
						 str, symbol_to_string(matrix, c, str));
	return (1);
}

void	past_before(t_matrix *matrix)
{
	matrix_string_insert(matrix, matrix->cursor, get_buffer_content(), get_buffer_len());
}

void	past_after(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_right(matrix);
	matrix_string_insert(matrix, matrix->cursor, get_buffer_content(), get_buffer_len());
}

int normal_mode_del(t_matrix *matrix, t_uchar c)
{
	int	col;

	if (c == 'B')
	{
		col = matrix->cursor->col;
		matrix->cursor->col = get_cursor_pos_begin_word(matrix);
		matrix_string_delete(matrix, matrix->cursor->row, col);
	}
	if (c == 'W')
	{
		col = get_cursor_pos_next_word(matrix);
		matrix_string_delete(matrix, matrix->cursor->row, col);
	}
	if (c == 'E')
	{
		col = get_cursor_pos_end_word(matrix);
		matrix_string_delete(matrix, matrix->cursor->row, col);
	}
	return (1);
}

int normal_mode(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'd')
		return (normal_mode_del(matrix, c));
	if (c == ESC)
		return (1);
	if (check_default_shortcuts(matrix, c))
		return (1);
	if (c == 'W')
		return (move_cursor_next_word(matrix));
	if (c == 'B')
		return (move_cursor_begin_word(matrix));
	if (c == 'E')
		return (move_cursor_end_word(matrix));
	if (c == 'i')
	{
		g_vi_mode = INSERT_MODE;
		return (1);
	}
	if (c == 'a')
	{
		g_vi_mode = INSERT_MODE;
		return (move_cursor_right(matrix));
	}
	if (c == 'I')
	{
		g_vi_mode = INSERT_MODE;
		return (move_cursor_home(matrix));
	}
	if (c == 'A')
	{
		g_vi_mode = INSERT_MODE;
		return (move_cursor_end(matrix));
	}
	if (c == 'p')
		past_after(matrix);
	if (c == 'P')
		past_before(matrix);
	return (1);
}

int	vi_mode(t_matrix *matrix, t_uchar c)
{
	if (g_vi_mode == INSERT_MODE)
		return (insert_mode(matrix, c));
	if (g_vi_mode == NORMAL_MODE)
		return (normal_mode(matrix, c));
	return (1);
}
