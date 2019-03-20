#include <signal.h>
#include "shell.h"

static void		killpids(void *data)
{
	pid_t pid;

	pid = *(pid_t *)data;
	kill(pid, SIGINT);
	waitpid(pid, 0, WUNTRACED);
}

void			freepids(void **pids)
{
	vector_foreach(*pids, killpids);
	vector_free(pids);
	*pids = 0;
}
