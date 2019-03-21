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
	waitpid(*(pid_t*)vector_back(job.pids), &(job.status), WNOHANG);
	g_job = 1;
	job.state = state;
	vector_push_back(&g_jobs, &job);
	ft_putstr_fd("[", STDERR_FILENO);
	ft_putnbr_fd(vector_get_len(g_jobs), STDERR_FILENO);
	ft_putstr_fd("] ", STDERR_FILENO);
	ft_putnbr_fd(pid, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
