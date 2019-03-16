#include "readline.h"
#include "shell.h"

static void actions_free(t_modification *modif)
{
	if (modif->len == 0 || modif->cur == modif->len - 1)
		return ;
	while (modif->cur != modif->len - 1)
	{
		action_free(modif->actions[modif->len - 1]);
		modif->len--;
	}
}

void		action_add(t_cursor start, t_cursor end, const char *buf, int act)
{
	t_modification	*modif;
	t_action		*action;

	modif = g_history->matrix[g_history->cur]->modif;
	actions_free(modif);
	if (modif->len == modif->size)
		modification_resize(modif, modif->size * RATIO, modif->size);
	modif->cur = modif->len;
	modif->actions[modif->cur] = (t_action *)xmalloc(sizeof(t_action));
	action = modif->actions[modif->cur];
	modif->len++;
	action->buf = (char *)xmalloc(sizeof(char) * (end.col - start.col + 1));
	action->act = act;
	ft_memcpy(action->buf, buf, end.col - start.col);
	action->start = start;
	action->end = end;
}
