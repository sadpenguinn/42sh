#include <signal.h>
#include "builtins.h"
#include "shell.h"

static int		bg_parse_args(char **av)
{
	if (!av || !av[1])
		return (SHERR_ERR);
	if (!av[2])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "bg", "");
		return (SHERR_ERR);
	}
	if (av[3])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "bg", av[3]);
		return (SHERR_ERR);
	}
	return (SHERR_OK);
}

int				built_bg(char **av, char **env)
{
	size_t	len;
	pid_t	pid;
	pid_t	p;
	size_t	i;

	i = 0;
	env = NULL;
	if ((bg_parse_args(av) == SHERR_ERR))
		return (SHERR_ERR);
	pid = ft_atoi(av[2]);
	len = vector_get_len(av[1]);
	if ((size_t)pid >= len)
	{
		sputcmderr("No running process", "bg", av[2]);
		return (SHERR_ERR);
	}
	while (i < len)
	{
		if ((p = *(pid_t *)vector_get_elem(g_pids, i)) == pid)
		{
			killpg(p, SIGCONT);
			return (SHERR_OK);
		}
		i++;
	}
	sputcmderr("No running process", "bg", av[2]);
	return (SHERR_ERR);
}
