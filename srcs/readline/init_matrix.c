#include "readline.h"
#include "shell.h"

t_matrix *init_matrix(void)
{
	t_matrix *matrix;

	matrix = xmalloc(sizeof(t_matrix));
	matrix->lines = (t_line **)xmalloc(sizeof(t_line *) * MATRIX_DEFAULT);
	matrix->size = MATRIX_DEFAULT;
	matrix->len = 1;
	matrix->lines[0] = init_line();
	matrix->cursor = (t_cursor *)xmalloc(sizeof(t_cursor));
	matrix->cursor->row = 0;
	matrix->cursor->col = 0;
	matrix->last_offset = 0;
	matrix->left_limit = 0;
	matrix->right_limit = 0;
	return (matrix);
}
