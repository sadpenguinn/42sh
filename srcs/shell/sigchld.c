#include <signal.h>
#include "shell.h"
#include "readline.h"
#include "signals.h"

void		(*g_sigchld)(int) = &handle_sigchld;

static void		stopped(int num, pid_t pid, int sig)
{
	ft_putstr_fd("[", STDERR_FILENO);
	ft_putnbr_fd(num, STDERR_FILENO);
	ft_putstr_fd("]", STDERR_FILENO);
	ft_putstr_fd(" + ", STDERR_FILENO);
	ft_putnbr_fd(pid, STDERR_FILENO);
	ft_putstr_fd(" suspended (", STDERR_FILENO);
	if (sig == SIGSTOP)
		ft_putstr_fd("SIGSTOP", STDERR_FILENO);
	if (sig == SIGTSTP)
		ft_putstr_fd("SIGTSTP", STDERR_FILENO);
	if (sig == SIGTTIN)
		ft_putstr_fd("SIGTTIN", STDERR_FILENO);
	if (sig == SIGTTOU)
		ft_putstr_fd("SIGTTOU", STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
}

static void		exited(int num, pid_t pid, int res)
{
	ft_putstr_fd("[", STDERR_FILENO);
	ft_putnbr_fd(num, STDERR_FILENO);
	ft_putstr_fd("]", STDERR_FILENO);
	ft_putstr_fd(" - ", STDERR_FILENO);
	ft_putnbr_fd(pid, STDERR_FILENO);
	ft_putstr_fd(" done (", STDERR_FILENO);
	ft_putnbr_fd(res, STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
}

static void		signaled(int num, pid_t pid, int sig)
{
	ft_putstr_fd("[", STDERR_FILENO);
	ft_putnbr_fd(num, STDERR_FILENO);
	ft_putstr_fd("]", STDERR_FILENO);
	ft_putstr_fd(" - ", STDERR_FILENO);
	ft_putnbr_fd(pid, STDERR_FILENO);
	ft_putstr_fd(" terminated (", STDERR_FILENO);
	if (sig == SIGALRM)
		ft_putstr_fd("SIGFPE", STDERR_FILENO);
	if (sig == SIGHUP)
		ft_putstr_fd("SIGHUP", STDERR_FILENO);
	if (sig == SIGKILL)
		ft_putstr_fd("SIGKILL", STDERR_FILENO);
	if (sig == SIGINT)
		ft_putstr_fd("SIGINT", STDERR_FILENO);
	if (sig == SIGPIPE)
		ft_putstr_fd("SIGPIPE", STDERR_FILENO);
	if (sig == SIGQUIT)
		ft_putstr_fd("SIGQUIT", STDERR_FILENO);
	if (sig == SIGSEGV)
		ft_putstr_fd("SIGSEGV", STDERR_FILENO);
	if (sig == SIGTERM)
		ft_putstr_fd("SIGTERM", STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
}

static int		check_status(int num, pid_t pid, t_job *job)
{
	int		status;

	if (!waitpid(pid, &status, WNOHANG | WUNTRACED))
		return (0);
	if (WIFSTOPPED(status))
	{
		stopped(num, pid, WSTOPSIG(status));
		job->state = JOB_STOP;
		return (0);
	}
	if (WIFCONTINUED(status))
	{
		ft_putstr_fd("[", STDERR_FILENO);
		ft_putnbr_fd(num, STDERR_FILENO);
		ft_putstr_fd("] ", STDERR_FILENO);
		ft_putnbr_fd(pid, STDERR_FILENO);
		ft_putstr_fd(" continued\n", STDERR_FILENO);
		job->state = JOB_RUN;
		return (0);
	}
	if (WIFEXITED(status))
		exited(num, pid, WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		signaled(num, pid, WTERMSIG(status));
	return (1);
}

void			handle_sigchld(int sig)
{
	size_t	count;
	size_t	i;
	t_job	*job;
	int		pid;

	(void)sig;
	if (!(count = vector_get_len(g_jobs)))
		return ;
	i = 0;
	while (i < count)
	{
		job = (t_job *)vector_get_elem(g_jobs, i);
		pid = *(pid_t*)vector_back(job->pids);
		i++;
		if (!check_status(i, pid, job))
			continue ;
		i--;
		count--;
		freepids(&(job->pids));
		vector_del_elem(&g_jobs, i);
	}
}
