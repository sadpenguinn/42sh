#include "readline.h"
#include "array.h"

int print_default(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	add_cursor_offset(matrix->last_offset);
	add_cursor_text(matrix);
	array_flush();
	return (1);
}

int	print_lines(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	array_flush();
	return (1);
}

int print_autocomplete(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	add_lines_text(matrix);
	array_add("\nmain.c  readline.c  array.c\n", strlen("\nmain.c  readline.c  array.c\n"));
	array_flush();
	print_prompt();
	matrix->last_offset = 0;
	return (1);
}
