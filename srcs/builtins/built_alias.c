#include "builtins.h"
#include "shell.h"

static int		alias_parse_params(char **av)
{
	if (!av[1] || !ft_strcmp(av[1], "-p"))
		return (alias_print_aliases());
	else if (av[1][0] == '-')
		return (alias_print_error(av[1]));
	else
		return (alias_parse_assignments(av));
}

/*
** Alias builtin
** alias [-p] [name[=value] ...]
**  -p flag means - print list of all aliases
*/

int					built_alias(char **av, char **env)
{
	env = NULL;
	return (alias_parse_params(av));
}
