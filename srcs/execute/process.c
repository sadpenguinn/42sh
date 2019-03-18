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

pid_t	xfork(void)
{
	pid_t	pid;

	if (!(pid = fork()))
		return (pid);
	if (g_pgid == -1)
		g_pgid = pid;
	setpgid(pid, g_pgid);
	if (g_isjob == EC_NOFG)
		tcsetpgrp(0, g_pgid);
	return (pid);
}

int		xwaitpid(pid_t pid, int options)
{
	int		status;
	pid_t	res;

	(void)options;
	res = waitpid(pid, &status, WUNTRACED);
	if (WIFSTOPPED(status))
	{
		vector_push_back(&g_jobs, &pid);
		printf("[%lu] + %d suspended\n", vector_get_len(g_jobs), pid);
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (cmdexitsig(pid, WTERMSIG(status)));
	return (EXIT_FAILURE);
}
