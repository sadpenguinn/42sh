#include "../includes/libalias.h"

void	alias_free_arr(char ***arr)
{
	int		i;

	i = 0;
	if (!arr && !*arr)
		return ;
	while ((*arr)[i])
	{
		free((*arr)[i]);
	}
	free((*arr));
	*arr = NULL;
}
