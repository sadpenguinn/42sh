/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:25:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

static int	pipe_create(t_astree *root, int fd[2], int isfork)
{
	int		pipefd[2];
	int		cmdfd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipefd) == -1)
		return (pipeerror());
	fcntl(pipefd[0], F_SETFD, FD_CLOEXEC);
	fcntl(pipefd[1], F_SETFD, FD_CLOEXEC);
	cmdfd[0] = fd[0];
	cmdfd[1] = pipefd[1];
	if (!(pid = xfork()))
		exit(execcmd(root->left, cmdfd, 1));
	close(cmdfd[1]);
	fd[0] = pipefd[0];
	status = execpipes(root->right, fd, isfork);
	if (!g_job)
		kill(pid, SIGINT);
	xwaitpid(pid, WUNTRACED);
	return (status);
}

int			execpipes(t_astree *root, int fd[2], int isfork)
{
	pid_t	pid;

	if (root->right)
		return (pipe_create(root, fd, isfork));
	if (!(pid = xfork()))
		exit(execcmd(root->left, fd, 1));
	close(fd[0]);
	return (xwaitpid(pid, WUNTRACED));
}
