#include "readline.h"
#include "shell.h"

void	modification_resize(t_modification *modif, size_t new_size, size_t old_size)
{
	modif->actions = (t_action **)xrealloc(modif->actions,
			sizeof(t_action *) * new_size, sizeof(t_action *) * old_size);
	modif->size = new_size;
}
