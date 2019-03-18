#include "builtins.h"
#include "shell.h"
#include "execute.h"
#include <signal.h>

int				built_fg(char **av, char **env)
{
	av = NULL;
	env = NULL;

	pid_t	pid;
	pid_t	pgid;

	if (!vector_get_len(g_jobs))
		return (0);
	pid = *(pid_t *)vector_back(g_jobs);
	vector_pop_back(&g_jobs);
	pgid = getpgid(pid);
	tcsetpgrp(0, pgid);
	killpg(pgid, SIGCONT);
	xwaitpid(pgid, 0);
	tcsetpgrp(0, getpgid(getpid()));

	return (SHERR_OK);
}
