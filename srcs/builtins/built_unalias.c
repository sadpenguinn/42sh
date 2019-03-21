#include "builtins.h"
#include "shell.h"

static int		unalias_print_usage(void)
{
	sputcmderr("Must be called with argument or flag", "unalias", "");
	return (SHERR_OK);
}

static int		unalias_remove_all(void)
{
	alias_clean(&g_aliases);
	g_aliases = alias_init(INITIAL_ALIASES_SIZE);
	return (SHERR_OK);
}

static int		unalias_remove_alias(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if ((alias_delete(av[i], g_aliases) == ALIAS_ERR))
		{
			sputcmderr(sstrerr(SHERR_NSE), "unalias", av[i]);
			return (SHERR_ERR);
		}
		i++;
	}
	return (SHERR_OK);
}

static int		unalias_parse_params(char **av)
{
	if (!av[1])
		return (unalias_print_usage());
	else if (!ft_strcmp(av[1], "-a"))
		return (unalias_remove_all());
	else
		return (unalias_remove_alias(av));
}

/*
** unalias [-a] [name … ]
** -a removes all variables
*/

int				built_unalias(char **av, char **env)
{
	env = NULL;
	return (unalias_parse_params(av));
}
