#include "builtins.h"
#include "shell.h"
#include "execute.h"
#include <signal.h>

void			killpids(void *data)
{
	pid_t pid;

	pid = *(pid_t *)data;
	kill(SIGINT, pid);
	waitpid(pid, 0, WUNTRACED);
}

int				built_fg(char **av, char **env)
{
	av = NULL;
	env = NULL;

	t_job	*job;
	pid_t	pid;
	pid_t	pgid;

	if (av && av[1] && ft_str_is_numeric(av[2]))
	{
		// Delete i-element here
		if (!vector_get_len(g_jobs))
			return (0);
		job = vector_back(g_jobs);
		vector_pop_back(&g_jobs);
	}
	else
	{
		if (!vector_get_len(g_jobs))
			return (0);
		job = vector_back(g_jobs);
		vector_pop_back(&g_jobs);
	}
	g_pids = job->pids;
	pid = *(pid_t *)vector_back(g_pids);
	pgid = getpgid(pid);
	tcsetpgrp(0, pgid);
	/* if (job->state == JOB_STOP) */
		killpg(pgid, SIGCONT);
	xwaitpid(pid, WUNTRACED);
	if (!g_pids)
		return (SHERR_OK);
	vector_foreach(g_pids, killpids);
	return (SHERR_OK);
}
