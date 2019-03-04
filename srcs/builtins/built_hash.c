#include "builtins.h"
#include "shell.h"

void	print_bin(char *key, char *value)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putendl(value);
}

static void		build_hash_parse(char **av)
{
	t_hshtb	*cell;
	char 	*path;
	int 	i;

	if (!ft_strcmp(av[1], "-p"))
	{
		if (av[2] && av[3])
		{
			path = ft_strjoin(av[2], "/", 0);
			path = ft_strjoin(path, av[3], 1);
			if (access(path, X_OK) == -1)
			{
				ft_strdel(&path);
				return ;
			}
			hash_delete(av[3], g_path);
			hash_insert(av[3], av[2], g_path);
			ft_strdel(&path);
		}
		else
			return ;
	}
	else if (!ft_strcmp(av[1], "-R"))
	{
		destroy_path();
		init_path();
	}
	else if (!ft_strcmp(av[1], "-d"))
	{
		if (!av[2])
			return ;
		i = 2;
		while (av[i])
		{
			hash_delete(av[i], g_path);
			i++;
		}
	}
	else if (!ft_strcmp(av[1], "-t"))
	{
		if (!av[2])
			return ;
		i = 2;
		while (av[i])
		{
			if ((cell = hash_find(av[i], g_path)))
				print_bin(cell->key, cell->value);
			i++;
		}
	}
	else if (!ft_strcmp(av[1], "-l"))
	{
		if (!av[2])
			hash_foreach(g_path, print_bin);
		else
		{
			i = 2;
			while (av[i])
			{
				if ((cell = hash_find(av[i], g_path)))
					print_bin(cell->key, cell->value);
				i++;
			}
		}
	}
	else
		return ;
}

int		built_hash(char **av, char **env)
{
	env = NULL;
	if (!av[1])
	{
		destroy_path();
		init_path();
		hash_foreach(g_path, print_bin);
	}
	else
		build_hash_parse(av);
	return (SHERR_OK);
}
