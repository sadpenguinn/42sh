#include "../includes/libalias.h"

/*
** Iterates the table
*/

int		alias_foreach(t_alias *alias, void (f)(char *key, char **value))
{
	t_aliastb	*ptr;
	size_t		size;
	size_t		i;

	if (!alias || !alias->table || !f)
		return (ALIAS_ERR);
	i = 0;
	size = alias->size;
	ptr = alias->table;
	while (i < size)
	{
		if (ptr->key)
			(f)(ptr->key, ptr->value);
		ptr++;
		i++;
	}
	return (ALIAS_OK);
}
