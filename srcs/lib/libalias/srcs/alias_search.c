#include "../includes/libalias.h"

static t_aliastb		*alias_bsearch(t_alias *alias, t_aindex index,
										t_aliastb *ptr, const char *key)
{
	t_aindex	i;

	i = 0;
	ptr = alias->table;
	while (i < index && (ptr->key && ft_strcmp(ptr->key, key)))
	{
		ptr++;
		i++;
	}
	if (i == index)
		return (NULL);
	return (ptr);
}

/*
** Internal function for search empty cell
*/

t_aliastb				*alias_search(const char *key, t_alias *alias,
										t_aindex index)
{
	t_aliastb	*ptr;

	ptr = alias->table + index;
	while (index < alias->size && (ptr->key && ft_strcmp(ptr->key, key)))
	{
		ptr++;
		index++;
	}
	if (index == alias->size)
		if (!(ptr = alias_bsearch(alias, index, ptr, key)))
			return (NULL);
	return (ptr);
}
