#include "../includes/libalias.h"

/*
** Dan Bernstein hashing algorithm for variable length strings
** http://www.cse.yorku.ca/~oz/hash.html
*/

static t_aindex		djb2(const char *content)
{
	t_aindex	index;
	size_t		i;
	int			c;

	i = 0;
	index = 5381;
	while (content[i])
	{
		c = content[i];
		index = ((index << 5) + index) + c;
		i++;
	}
	return (index);
}

/*
** Looks up the index of an item in a table.
** At alias or key == NULL, behavior is undefined
*/

t_aindex			alias_index(const char *key, t_alias *alias)
{
	t_aindex	index;

	index = djb2(key);
	index = index % alias->size;
	return (index);
}
