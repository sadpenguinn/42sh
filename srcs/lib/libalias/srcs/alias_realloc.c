#include "../includes/libalias.h"

static void		alias_realloc_fill(t_alias *alias, t_alias *new_alias)
{
	alias_foreach(alias, alias_free_fileds);
	free(alias->table);
	alias->table = new_alias->table;
	alias->size = new_alias->size;
	alias->filled = new_alias->filled;
	free(new_alias);
}

int			alias_realloc(t_alias *alias, size_t new_size)
{
	t_alias		*new_alias;
	t_aliastb	*current;
	size_t		i;

	i = 0;
	new_alias = alias_init(new_size);
	current = alias->table;
	while (i < alias->size)
	{
		if (current->key)
		{
			if (!(alias_insert(current->key, current->value, new_alias)))
			{
				alias_clean(&alias);
				return (0);
			}
		}
		current++;
		i++;
	}
	alias_realloc_fill(alias, new_alias);
	return (1);
}
