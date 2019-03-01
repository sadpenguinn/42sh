#include "vector.h"
#include <unistd.h>
#include "execute.h"

pid_t	xfork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid)
		vector_push_back(&g_pids, &pid);
	return (pid);
}

pid_t	xwaitpid(pid_t pid, int *stat_loc, int options)
{
	pid_t	res;

	res = waitpid(pid, stat_loc, options);
	vector_pop_back(&g_pids);
	return (res);
}
