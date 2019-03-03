#include "readline.h"
#include "shell.h"

t_matrix	*matrix_init(void)
{
	t_matrix	*matrix;

	matrix = (t_matrix *)xmalloc(sizeof(t_matrix));
	matrix->lines = (t_line **)xmalloc(sizeof(t_line *) * MATRIX_DEFAULT_SIZE);
	matrix->size = MATRIX_DEFAULT_SIZE;
	matrix->len = 0;
	matrix->cursor = (t_cursor *)xmalloc(sizeof(t_cursor));
	matrix->cursor->row = 0;
	matrix->cursor->col = 0;
	matrix->left_limit = 0;
	matrix->right_limit = 0;
	matrix->single_quotes = 0;
	matrix->double_quotes = 0;
	return (matrix);
}
