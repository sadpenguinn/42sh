#include "builtins.h"
#include "conditions.h"

int		built_test(char **av, char **env)
{
	env = NULL;
	if (!av)
		return (SHERR_ERR);
	return (conditions(++av));
}
