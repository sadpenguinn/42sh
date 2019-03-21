#include "builtins.h"
#include "conditions.h"

/*
** Evaluate a conditional expression expr
** and return a status of 0 (true) or 1 (false)
** test expr
*/

int		built_test(char **av, char **env)
{
	env = NULL;
	if (!av)
		return (SHERR_ERR);
	return (conditions(++av));
}
