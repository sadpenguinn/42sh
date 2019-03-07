#include <shell.h>
#include "builtins.h"

static int		built_export_delete(char **av)
{
	int 	i;

	i = 2;
	while (av[i])
	{
		sunsetenv(av[i], ENV_ALL);
		i++;
	}
	return (SHERR_OK);
}

static int		built_export_assignment(char **av)
{
	char 	**pair;
	int 	i;

	i = 1;
	while (av[i])
	{
		pair = split_env(av[i]);
		ssetenv(pair[0], pair[1], ENV_EXP);
		hash_print(g_hash_env);
		free_str_arr(&pair);
		i++;
	}
	return (SHERR_OK);
}

static int		built_export_parse(char **av, char **env)
{
	if (!ft_strcmp(av[1], "-n"))
		return (built_export_delete(av));
	else if (!ft_strcmp(av[1], "-p"))
	{
		if (av[2])
		{
			sputcmderr(sstrerr(SHERR_INVSNTX), "export", av[2]);
			return (SHERR_ERR);
		}
		print_str_arr(env);
		return (SHERR_OK);
	}
	else
		return (built_export_assignment(av));
}

int 			built_export(char **av, char **env)
{
	if (av[1])
		return (built_export_parse(av, env));
	else
		print_str_arr(env);
	return (SHERR_OK);
}
