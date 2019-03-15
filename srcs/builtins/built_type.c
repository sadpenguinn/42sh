#include "shell.h"
#include "execute.h"
#include "builtins.h"

static void		type_print_arr(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		ft_putchar(' ');
		i++;
	}
	if (i > 0)
		ft_putchar('\n');
}

static int		type_parse_flags(char **av, int *flags)
{
	int		i;

	i = 1;
	ft_memset(flags, '\0', sizeof(int) * 5);
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-a"))
			flags[0] = 1;
		else if (!ft_strcmp(av[i], "-f"))
			flags[1] = 1;
		else if (!ft_strcmp(av[i], "-p"))
			flags[2] = 1;
		else if (!ft_strcmp(av[i], "-t"))
			flags[3] = 1;
		else if (!ft_strcmp(av[i], "-P"))
			flags[4] = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

static int		type_find_function(char *arg, int *flags)
{
	t_func	*function;
	size_t	len;
	size_t	i;

	i = 0;
	len = vector_get_len(g_func);
	while (i < len)
	{
		function = (t_func *)vector_get_elem(g_func, i);
		if (!ft_strcmp(function->name, arg))
		{
			ft_putstr(arg);
			if (flags[3])
				ft_putendl(" function");
			else
				ft_putendl(" is a shell function");
			return (1);
		}
		i++;
	}
	return (0);
}

static int		type_find_alias(char *arg, int *flags)
{
	t_aliastb	*alias;

	if (!(alias = alias_find(arg, g_aliases)))
		return (0);
	ft_putstr(arg);
	if (flags[3])
		ft_putendl(" alias");
	else
	{
		ft_putstr(" is an alias for ");
		type_print_arr(alias->value);
	}
	return (1);
}

static int		type_find_builtin(char *arg, int *flags)
{
	// Needs refactoring
	if (!ft_strcmp(arg, "alias") || !ft_strcmp(arg, "bg"))
	{
		ft_putstr(arg);
		if (flags[3])
			ft_putendl(" builtint");
		else
			ft_putendl(" is a builtin");
		return (1);
	}
	return (0);
}

static int		type_find_keyword(char *arg, int *flags)
{
	if (!ft_strcmp(arg, "!") || !ft_strcmp(arg, "{")
		|| !ft_strcmp(arg, "}") || !ft_strcmp(arg, "case")
		|| !ft_strcmp(arg, "do") || !ft_strcmp(arg, "done")
		|| !ft_strcmp(arg, "elif") || !ft_strcmp(arg, "else")
		|| !ft_strcmp(arg, "esac") || !ft_strcmp(arg, "fi")
		|| !ft_strcmp(arg, "for") || !ft_strcmp(arg, "if")
		|| !ft_strcmp(arg, "in") || !ft_strcmp(arg, "then")
		|| !ft_strcmp(arg, "function") || !ft_strcmp(arg, "]]")
		|| !ft_strcmp(arg, "select") || !ft_strcmp(arg, "[["))
	{
		ft_putstr(arg);
		if (flags[3])
			ft_putendl(" keyword");
		else
			ft_putendl(" is a keyword");
		return (1);
	}
	return (0);
}

static int		type_find_bin(char *arg, int *flags)
{
	t_hshtb	*bin;

	if (!(bin = hash_find(arg, g_path)))
		return (0);
	ft_putstr(arg);
	if (flags[3])
		ft_putendl(" file");
	else
	{
		ft_putstr(" is ");
		ft_putstr(bin->value);
		ft_putchar('\n');
	}
	return (1);
}

static int		type_iterate_args(char **av, int i, int *flags)
{
	int		flag;

	flag = SHERR_OK;
	while (av[i])
	{
		if ((type_find_alias(av[i], flags) || type_find_function(av[i], flags)
			|| type_find_builtin(av[i], flags) || type_find_keyword(av[i], flags)
			|| type_find_bin(av[i], flags)) && flag == SHERR_OK)
			flag = SHERR_OK;
		else
			flag = SHERR_ERR;
		i++;
	}
	return (flag);
}

int				built_type(char **av, char **env)
{
	int		flags[5];
	int		i;

	env = NULL;
	i = type_parse_flags(av, flags);
	return (type_iterate_args(av, i, flags));
}
