#include "../includes/libalias.h"

/*
** The function just cleans the table
*/

int		alias_clean(t_alias **alias)
{
	if (!alias || !*alias)
		return (ALIAS_ERR);
	if (!(*alias)->table)
	{
		free(*alias);
		return (ALIAS_ERR);
	}
	alias_foreach(*alias, alias_free_fileds);
	free((*alias)->table);
	free(*alias);
	*alias = NULL;
	return (ALIAS_OK);
}
