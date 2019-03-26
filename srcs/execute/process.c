/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 21:34:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>
#include "execute.h"
#include <signal.h>

pid_t	xfork(void)
{
	pid_t	pid;

	if (!(pid = fork()))
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		return (pid);
	}
	vector_push_back(&g_pids, &pid);
	if (g_pgid == -1)
		g_pgid = pid;
	if (setpgid(pid, g_pgid) == -1)
		setpgid(pid, (g_pgid = getpgid(pid)));
	if (!g_isjob)
		tcsetpgrp(0, g_pgid);
	return (pid);
}

int		xwaitpid(pid_t pid, int options)
{
	int		status;
	pid_t	res;

	(void)options;
	res = waitpid(pid, &status, options);
	if (g_job)
		return (EXIT_SUCCESS);
	if (!g_job)
		tcsetpgrp(0, getpgrp());
	if (WIFSTOPPED(status))
		return (addjob(JOB_STOP, 0));
	if (g_pgid)
		vector_pop_back(&g_pids);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (cmdexitsig(pid, WTERMSIG(status)));
	return (EXIT_FAILURE);
}
