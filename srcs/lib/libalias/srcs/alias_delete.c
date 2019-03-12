#include "../includes/libalias.h"

/*
** Remove one cell from the table
*/

int		alias_delete(const char *key, t_alias *alias)
{
	t_aliastb		*cell;

	if ((cell = alias_find(key, alias)) == ALIAS_ERR)
		return (ALIAS_ERR);
	ft_strdel(&cell->key);
	alias_free_arr(&cell->value);
	ft_memset(cell, '\0', sizeof(t_aliastb));
	alias->filled--;
	return (ALIAS_OK);
}
