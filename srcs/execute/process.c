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

int		xwaitpid(pid_t pid, int options)
{
	int		status;
	pid_t	res;

	res = waitpid(pid, &status, options);
	vector_pop_back(&g_pids);
	if (res < 0)
		return (res);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (cmdexitsig(pid, WTERMSIG(status)));
	return (EXIT_FAILURE);
}
