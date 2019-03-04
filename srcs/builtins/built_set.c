#include "builtins.h"
#include "readline.h"
#include "shell.h"

static int 		built_set_usage(void)
{
	ft_putendl("Huita");
	return (SHERR_ERR);
}

static int		built_set_parse(char **av)
{
	if (!ft_strcmp(av[1], "-o"))
	{
		if (!ft_strcmp(av[2], "vi"))
		{
			g_mode = VI;
			g_vi_mode = INSERT_MODE;
			return (SHERR_OK);
		}
		else if (!ft_strcmp(av[2], "emacs"))
		{
			g_mode = READLINE;
			return (SHERR_OK);
		}
		else if (!ft_strcmp(av[2], "echoe"))
		{
			g_echoe = g_echoe == TRUE ? FALSE : TRUE;
			return (SHERR_OK);
		}
		else
		{
			ft_putstr("vi:\t\t");
			ft_putendl(g_mode == VI ? "on" : "off");
			ft_putstr("emacs:\t\t");
			ft_putendl(g_mode == READLINE ? "on" : "off");
			ft_putstr("echoe:\t\t");
			ft_putendl(g_echoe == TRUE ? "on" : "off");
			return (SHERR_OK);
		}
	}
	else
		return (built_set_usage());
}

int				built_set(char **av, char **env)
{
	if (av[1])
		return (built_set_parse(av));
	else
		print_str_arr(env);
	return (SHERR_OK);
}
