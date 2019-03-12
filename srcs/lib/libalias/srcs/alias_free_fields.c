#include "../includes/libalias.h"

/*
** Internal function for remove hash fields
*/

void		alias_free_fileds(char *key, char **value)
{
	free(key);
	alias_free_arr(&value);
}
