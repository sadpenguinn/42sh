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

void		*threadcmd(void *data)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)data;
	execcmd(cmd->root, cmd->fd, cmd->job, cmd->ppid);
	return (0);
}

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

int			execpipes(t_astree	*root, int fd[2], int job, void *ppid)
{
	int			pipefd[2];
	pthread_t	tid;
	t_cmd		cmd;
	void 		*res;

	cmd.root = root->left;
	cmd.job = job;
	cmd.ppid = ppid;
	if (root->right)
	{
		if (pipe_create(fd, cmd.fd, pipefd) == -1)
			return (-1);
		if (pthread_create(&tid, 0, threadcmd, &cmd))
			return (threaderror());
pthread_join(tid, &res);
		fd[0] = pipefd[0];
		return (execpipes(root->right, fd, job, pipe));
		return (0);
	}
	else
	{
		ft_memmove(cmd.fd, fd, sizeof(int) * 2);
		if (pthread_create(&tid, 0, threadcmd, &cmd))
			return (threaderror());
		pthread_join(tid, &res);
		return (0);
	}
	return (0);
}
