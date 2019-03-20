#include "builtins.h"
#include "shell.h"
#include "execute.h"
#include <signal.h>
#include <errno.h>

void			killpids(void *data)
{
	pid_t pid;

	pid = *(pid_t *)data;
	kill(pid, SIGINT);
	waitpid(pid, 0, WUNTRACED);
}

int				built_fg(char **av, char **env)
{
	t_job	*job;
	pid_t	pid;
	pid_t	pgid;
	size_t	len;
	size_t	i;

	env = NULL;
	if (!(len = vector_get_len(g_jobs)))
		return (0);
	if (av && av[1] && ft_str_is_numeric(av[2]))
	{
		i = (size_t)ft_atoi(av[2]);
		if (i > len)
			return (0);
		job = vector_get_elem(g_jobs, i);
		vector_del_elem(&g_jobs, i);
	}
	else
	{
		job = vector_back(g_jobs);
		vector_pop_back(&g_jobs);
	}
	g_pids = job->pids;
	pid = *(pid_t *)vector_back(g_pids);
	pgid = getpgid(pid);
	tcsetpgrp(0, pgid);
	if (job->state == JOB_STOP)
		killpg(pgid, SIGCONT);
	xwaitpid(pid, WUNTRACED);
	if (g_job)
		return (SHERR_OK);
	vector_foreach(g_pids, killpids);
	return (SHERR_OK);
}
