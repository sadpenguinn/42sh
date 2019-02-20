#include "readline.h"
#include "shell.h"

void    matrix_resize(t_matrix *matrix, int new_size, int old_size)
{
	matrix->lines = (t_line **)xrealloc(matrix->lines,
	                                    sizeof(t_line *) * new_size, sizeof(t_line *) * old_size);
	matrix->size = new_size;
}
