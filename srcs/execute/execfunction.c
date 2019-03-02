/*
**	FN - FunctioN
**	FNBD - FunctioN BoDy
**
** FN(content:WORD)
**   \
**    FNBD
*/

#include "execute.h"

int		execfunction(t_astree *root)
{
	t_func	*func;

	func = xmalloc(sizeof(t_func));
	func->name = ft_strdup(root->content);
	func->func = root->right;
	root->right = 0;
	return (EXIT_SUCCESS);
}
