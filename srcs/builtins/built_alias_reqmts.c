#include "builtins.h"
#include "shell.h"

int			alias_print_error(char *arg)
{
	sputcmderr(sstrerr(SHERR_INVSNTX), "alias", arg);
	return (SHERR_ERR);
}

void		alias_print_alias(char *key)
{
	t_aliastb	*alias;
	int				i;

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

int			alias_parse_assignments(char **av)
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

int			alias_print_aliases(void)
{
	alias_print(g_aliases);
	return (SHERR_OK);
}
