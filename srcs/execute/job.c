#include "execute.h"

int		addjob(int state, pid_t pid)
{
	t_job	job;

	if (pid > 0)
	{
		job.pids = vector_create(sizeof(pid_t));
		vector_push_back(&(job.pids), &pid);
	}
	else
	{
		if (!g_pids)
			return (EXIT_FAILURE);
		job.pids = g_pids;
		g_pids = 0;
	}
	job.state = state;
	vector_push_back(&g_jobs, &job);
	printf("[%lu] + suspended\n", vector_get_len(g_jobs));
	return (EXIT_FAILURE);
}
