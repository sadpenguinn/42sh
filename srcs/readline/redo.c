#include "readline.h"

static void	redo_delete(t_matrix *matrix, t_action *action)
{
	g_history->redo_undo = 1;
	*matrix->cursor = matrix_string_insert(matrix, action->start,
			action->buf, action->end.col - action->start.col);
	g_history->redo_undo = 0;
}

static void	redo_insert(t_matrix *matrix, t_action *action)
{
	g_history->redo_undo = 1;
	*matrix->cursor = matrix_string_delete(action->start, action->end);
	g_history->redo_undo = 0;
}

int			redo(t_matrix *matrix)
{
	t_modification	*modif;
	t_action		*action;

	modif = matrix->modif;
	if (modif->cur == modif->len - 1)
		return (1);
	modif->cur++;
	action = modif->actions[modif->cur];
	if (action->act == INSERT)
		redo_delete(matrix, action);
	else
		redo_insert(matrix, action);
	return (1);
}
