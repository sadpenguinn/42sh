#include "../includes/libalias.h"

/*
** Returns a pointer if there is match or NULL
*/

static t_aliastb	*alias_find_iter(t_alias *alias, t_aindex	index,
									  const char *key, t_aliastb *ptr)
{
	t_aindex	i;

	i = 0;
	if (index == alias->size)
	{
		index = i;
		i = 0;
		ptr = alias->table + i;
		while (i < index && (!ptr->key || (ptr->key &&
									ft_strcmp(key, ptr->key))))
		{
			ptr++;
			i++;
		}
		if (i == index)
			return (NULL);
	}
	return (ptr);
}

t_aliastb			*alias_find(const char *key, t_alias *alias)
{
	t_aindex	index;
	t_aliastb	*ptr;

	if (!alias || !alias->table || !key)
		return (NULL);
	index = alias_index(key, alias);
	ptr = alias->table + index;
	while (index < alias->size && (!ptr->key || (ptr->key &&
												ft_strcmp(key, ptr->key))))
	{
		ptr++;
		index++;
	}
	if (!(ptr = alias_find_iter(alias, index, key, ptr)))
		return (NULL);
	if (!ft_strcmp(key, ptr->key))
		return (ptr);
	return (NULL);
}
