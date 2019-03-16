#include "readline.h"

static void	undo_delete(t_matrix *matrix, t_action *action)
{
	g_history->redo_undo = 1;
	matrix_string_insert(matrix, action->start, action->buf, action->end.col - action->start.col);
	g_history->redo_undo = 0;
}

static void	undo_insert(t_action *action)
{
	g_history->redo_undo = 1;
	matrix_string_delete(action->start, action->end);
	g_history->redo_undo = 0;
}

int			undo(t_matrix *matrix)
{
	t_modification	*modif;
	t_action		*action;
	t_line			*line;

	modif = matrix->modif;
	if (modif->cur == 0)
		return (1);
	action = modif->actions[modif->cur];
	if (action->act == INSERT)
		undo_insert(action);
	else
		undo_delete(matrix, action);
	modif->cur--;
	line = matrix->lines[matrix->cursor->row];
	matrix->cursor->col = line->len;
	return (1);
}

int			large_undo_redo(t_matrix *matrix)
{
	if (matrix->modif->cur == 0)
	{
		while (matrix->modif->cur != matrix->modif->len - 1)
			redo(matrix);
		return (1);
	}
	while (matrix->modif->cur)
		undo(matrix);
	return (1);
}