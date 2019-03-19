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

	if (!vector_get_len(g_jobs))
		return (0);
	/* pid = *(pid_t *)vector_back(g_jobs); */
	/* vector_pop_back(&g_jobs); */
	/* pgid = getpgid(pid); */
	/* tcsetpgrp(0, pgid); */
	/* killpg(pgid, SIGCONT); */
	/* xwaitpid(pgid, WUNTRACED); */
	/* tcsetpgrp(0, getpgid(getpid())); */
	job = vector_back(g_jobs);
	vector_pop_back(&g_jobs);
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
