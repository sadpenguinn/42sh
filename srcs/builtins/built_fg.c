#include "builtins.h"
#include "shell.h"
#include "execute.h"
#include "signals.h"
#include <signal.h>
#include <errno.h>

static int		fg_parse_args(char **args)
{
	if (!args[1])
		return (1);
	if (args[1] && !ft_str_is_numeric(args[1]))
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[1]);
		return (0);
	}
	else if (args[1] && args[2] != 0)
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[2]);
		return (0);
	}
	else if (!ft_atoi(args[1]))
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[1]);
		return (0);
	}
	return (1);
}

static size_t	fg_get_index(char **av)
{
	size_t	i;
	size_t	len;

	if (!(len = vector_get_len(g_jobs)))
	{
		sputcmderr("No running jobs", "fg", av[1] ? av[1] : "current");
		return (0);
	}
	i = len;
	if (av[1] && ft_str_is_numeric(av[1]))
	{
		i = (size_t)ft_atoi(av[1]);
		if (i > len)
		{
			sputcmderr("No running jobs", "fg", av[2]);
			return (0);
		}
	}
	return (i);
}

int				built_fg(char **av, char **env)
{
	void	*pidstmp;
	t_job	job;
	pid_t	pid;
	pid_t	pgid;
	size_t	i;

	env = NULL;
	if (!(fg_parse_args(av)) || !(i = fg_get_index(av)))
		return (SHERR_ERR);
	i--;
	job = *(t_job *)vector_get_elem(g_jobs, i);
	vector_del_elem(&g_jobs, i);
	pidstmp = g_pids;
	g_pids = job.pids;
	pid = *(pid_t *)vector_back(g_pids);
	pgid = getpgid(pid);
	tcsetpgrp(0, pgid);
	killpg(pgid, SIGCONT);
	xwaitpid(pid, WUNTRACED);
	g_pids = pidstmp;
	if (g_job)
		return (SHERR_OK);
	freepids(&(job.pids));
	return (SHERR_OK);
}
