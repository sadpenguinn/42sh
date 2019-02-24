/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:25:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 16:44:05 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>

static int	pipe_create(int fd[2], int cmdfd[2], int pipefd[2])
{
	if (pipe(pipefd) == -1)
		return (pipeerror());
	fcntl(pipefd[0], F_SETFD, FD_CLOEXEC);
	fcntl(pipefd[1], F_SETFD, FD_CLOEXEC);
	cmdfd[0] = fd[0];
	cmdfd[1] = pipefd[1];
	return (0);
}

int			execpipes(t_astree	*root, int fd[2], int job, int isfork)
{
	int		pipefd[2];
	int		cmdfd[2];
	pid_t	pid;
	int		res;

	if (root->right)
	{
		if (pipe_create(fd, cmdfd, pipefd) == -1)
			return (-1);
		if (!(pid  = fork()))
			execcmd(root->left, cmdfd, 0, 1);
		close(cmdfd[1]);
		fd[0] = pipefd[0];
		res = execpipes(root->right, fd, job, isfork);
		waitpid(pid, 0, 0);
		return (res);
	}
	else
	{
		if (!(pid  = fork()))
			execcmd(root->left, fd, 0, 1);
		waitpid(pid, 0, 0);
		return (228);
	}
	return (0);
}
