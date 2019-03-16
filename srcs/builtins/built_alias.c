#include "builtins.h"
#include "shell.h"

static void		alias_print_alias(char *key)
{
	t_aliastb	*alias;
	int			i;

	i = 0;
	if (!(alias = alias_find(key, g_aliases)))
		return ;
	ft_putstr(alias->key);
	ft_putchar('=');
	while (alias->value[i])
	{
		ft_putstr(alias->value[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

static int		alias_parse_assignments(char **av)
{
	char	**arr;
	char	**value;
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_strchr(av[i], '='))
		{
			alias_print_alias(av[i]);
			i++;
			continue ;
		}
		arr = split_assignments(av[i]);
		value = ft_strsplit(arr[1], ' ');
		alias_insert(arr[0], value, g_aliases);
		free_str_arr(&value);
		free_str_arr(&arr);
		i++;
	}
	return (SHERR_OK);
}

static int		alias_print_aliases(void)
{
	alias_print(g_aliases);
	return (SHERR_OK);
}

static int		alias_parse_params(char **av)
{
	if (!av[1] || !ft_strcmp(av[1], "-p"))
		return (alias_print_aliases());
	else
		return (alias_parse_assignments(av));
}

int				built_alias(char **av, char **env)
{
	env = NULL;
	return (alias_parse_params(av));
}
