#include "readline.h"

int	vi_mode(t_uchar c)
{
	t_matrix	*matrix;

	matrix = g_history->matrix[g_history->cur];
	if (g_vi_mode == INSERT_MODE)
		return (insert_mode(matrix, c));
	if (g_vi_mode == NORMAL_MODE)
		return (normal_mode(matrix, c));
	if (g_vi_mode == REPLACE_MODE)
		return (replace_mode(matrix, c));
	return (1);
}
