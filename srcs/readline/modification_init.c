#include "readline.h"
#include "shell.h"

t_modification	*modification_init(void)
{
	t_modification	*modif;

	modif = (t_modification *)xmalloc(sizeof(t_modification));
	modif->actions = (t_action **)xmalloc(sizeof(t_action *) * MODIF_ARRAY_DEFAULT_SIZE);
	modif->size = MODIF_ARRAY_DEFAULT_SIZE;
	modif->len = 0;
	modif->cur = 0;
	return (modif);
}
