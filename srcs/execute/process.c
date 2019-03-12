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

	pid = fork();
	if (pid)
		vector_push_back(&g_pids, &pid);
	return (pid);
}

int		xwaiterr(pid_t pid)
{
	int		status;

	waitpid(pid, &status, WUNTRACED);
	if (!WIFSTOPPED(status))
		return (1);
	printf("[%lu] + %d suspended\n", vector_get_len(g_jobs) + 1, pid);
	return (1);
}

int		xwaitpid(pid_t pid, int options)
{
	int		status;
	pid_t	res;

	res = waitpid(pid, &status, options);
	printf("Proc end\n>>>%d\n", res);
	if (res < 0)
		return (xwaiterr(pid));
	vector_pop_back(&g_pids);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (cmdexitsig(pid, WTERMSIG(status)));
	return (EXIT_FAILURE);
}
