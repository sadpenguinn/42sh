#include "../includes/libalias.h"

/*
** Allocate alias table with passed size
*/

t_alias		*alias_init(size_t size)
{
	t_alias		*alias;
	t_aliastb	*table;

	if (ALIAS_PERCENTS_SIZE_REALLOC <= 0 || ALIAS_PERCENTS_FILLED_MAX <= 0 || !size)
		return (NULL);
	alias = (t_alias *)xmalloc(sizeof(t_alias));
	table = (t_aliastb *)xmalloc(sizeof(t_aliastb) * size);
	ft_memset(alias, '\0', sizeof(t_alias));
	ft_memset(table, '\0', sizeof(t_aliastb) * size);
	alias->table = table;
	alias->size = size;
	alias->filled = 0;
	return (alias);
}
