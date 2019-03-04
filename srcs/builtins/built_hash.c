#include "builtins.h"
#include "shell.h"

void	print_bin(char *key, char *value)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putendl(value);
}

int		built_hash(char **av, char **env)
{
	*av = NULL;
	env = NULL;
	hash_foreach(g_path, print_bin);
	return (SHERR_OK);
}
