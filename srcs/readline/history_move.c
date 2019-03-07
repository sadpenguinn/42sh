#include "readline.h"

int	move_history_prev(void)
{
	if (g_history->cur)
	{
		if (g_history->cur == g_history->len - 1)
		{
			matrix_del(&g_history->matrix[g_history->cur]);
			g_history->matrix[g_history->cur] = matrix_dup(g_history->cur_matrix);
		}
		matrix_del(&g_history->cur_matrix);
		g_history->cur_matrix = matrix_dup(g_history->matrix[--g_history->cur]);
		g_history->cur_matrix->cursor->row = g_history->cur_matrix->len - 1;
		g_history->cur_matrix->cursor->col =
				g_history->cur_matrix->lines[g_history->cur_matrix->len - 1]->len;
	}
	return (1);
}

int move_history_next(void)
{
	if (g_history->cur != g_history->len - 1)
	{
		matrix_del(&g_history->cur_matrix);
		g_history->cur_matrix = matrix_dup(g_history->matrix[++g_history->cur]);
		g_history->cur_matrix->cursor->row = g_history->cur_matrix->len - 1;
		g_history->cur_matrix->cursor->col =
				g_history->cur_matrix->lines[g_history->cur_matrix->len - 1]->len;
	}
	return (1);
}
