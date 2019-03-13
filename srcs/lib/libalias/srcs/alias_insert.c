#include "../includes/libalias.h"

static size_t			alias_check_avail(t_alias *alias)
{
	float		avail;
	float		filled;

	avail = (float)alias->size / (float)100 * (float)ALIAS_PERCENTS_FILLED_MAX;
	filled = (float)alias->filled;
	if (filled > avail)
	{
		return ((size_t)((float)alias->size / (float)100 *
						 (float)ALIAS_PERCENTS_SIZE_REALLOC) + alias->size);
	}
	return (0);
}

static t_aliastb		*alias_insert_cell(const char *key, char **value,
											t_alias *alias, t_aindex index)
{
	t_aliastb		*ptr;
	t_aliastb		new;

	if (!(ptr = alias_search(key, alias, index)))
		return (NULL);
	ft_strdel(&ptr->key);
	alias_free_arr(&ptr->value);
	new.key = ft_strdup(key);
	new.value = alias_cpy_arr(value);
	ft_memmove((void *)ptr, (void *)&new, sizeof(t_aliastb));
	alias->filled++;
	return (ptr);
}

/*
** Function inserts cell into the table. If cells count is greater
** then ALIAS_PERCENTS_FILLED_MAX define, table size will be increased by
** ALIAS_PERCENTS_SIZE_REALLOC
*/

t_aliastb				*alias_insert(const char *key, char **value,
							  			t_alias *alias)
{
	t_aindex	index;
	size_t		new_size;

	if (!alias || !alias->table || !key)
		return (NULL);
	if ((new_size = alias_check_avail(alias)))
		if (!(alias_realloc(alias, new_size)))
			return (NULL);
	index = alias_index(key, alias);
	return (alias_insert_cell(key, value, alias, index));
}
