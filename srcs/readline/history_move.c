#include "readline.h"

int	move_history_prev(void)
{
	if (g_history->cur)
	{
		if (g_history->cur == g_history->len - 1)
		{
			matrix_del(&g_history->matrix[g_history->cur]);
			g_history->matrix[g_history->cur] = matrix_dup(g_history->tmp);
		}
		matrix_del(&g_history->tmp);
		g_history->tmp = matrix_dup(g_history->matrix[--g_history->cur]);
		g_history->tmp->cursor->row = g_history->tmp->len - 1;
		g_history->tmp->cursor->col =
				g_history->tmp->lines[g_history->tmp->len - 1]->len;
	}
	return (1);
}

int move_history_next(void)
{
	if (g_history->cur != g_history->len - 1)
	{
		matrix_del(&g_history->tmp);
		g_history->tmp = matrix_dup(g_history->matrix[++g_history->cur]);
		g_history->tmp->cursor->row = g_history->tmp->len - 1;
		g_history->tmp->cursor->col =
				g_history->tmp->lines[g_history->tmp->len - 1]->len;
	}
	return (1);
}
