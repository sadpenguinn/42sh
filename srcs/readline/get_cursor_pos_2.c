#include "readline.h"

int	get_cursor_pos_next_word(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	while (line->buf[col] != ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (line->buf[col] == ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int get_cursor_pos_begin_word(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (line->buf[col] != ' ' && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (line->buf[col] == ' ' && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (line->buf[col] != ' ' && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	if (line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int get_cursor_pos_end_word(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (line->buf[col] != ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (line->buf[col] == ' ' && col < line->len - 1)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (line->buf[col] != ' ' && col < line->len - 1)
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col < line->len && line->buf[col] == ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	return (col);
}
