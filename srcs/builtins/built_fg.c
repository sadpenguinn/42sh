#include "builtins.h"
#include "shell.h"
#include "execute.h"
#include <signal.h>
#include <errno.h>

static int		fg_parse_args(char **args)
{
	if (args[1] && !ft_str_is_numeric(args[1]))
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[1]);
		return (0);
	}
	else if (args[1] && args[2])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[2]);
		return (0);
	}
	return (1);
}

int				built_fg(char **av, char **env)
{
	void	*pidstmp;
	t_job	*job;
	pid_t	pid;
	pid_t	pgid;
	size_t	len;
	size_t	i;

	env = NULL;
	if (!av || !av[0] || !(fg_parse_args(av)))
		return (SHERR_ERR);
	if (!(len = vector_get_len(g_jobs)))
	{
		sputcmderr("No running jobs", "fg", av[1] ? av[1] : "");
		return (SHERR_ERR);
	}
	if (av && av[1] && ft_str_is_numeric(av[2]))
	{
		i = (size_t)ft_atoi(av[2]);
		if (i > len)
		{
			sputcmderr("No running jobs", "fg", av[2]);
			return (SHERR_ERR);
		}
		job = vector_get_elem(g_jobs, i);
		vector_del_elem(&g_jobs, i);
	}
	else
	{
		job = vector_back(g_jobs);
		vector_pop_back(&g_jobs);
	}
	pidstmp = g_pids;
	g_pids = job->pids;
	pid = *(pid_t *)vector_back(g_pids);
	pgid = getpgid(pid);
	tcsetpgrp(0, pgid);
	killpg(pgid, SIGCONT);
	xwaitpid(pid, WUNTRACED);

	g_pids = pidstmp;
	if (g_job)
		return (SHERR_OK);
	/* vector_foreach(g_pids, killpids); */
	return (SHERR_OK);
}
