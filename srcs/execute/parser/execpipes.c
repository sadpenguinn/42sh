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

int		execpipes(t_astree	*root, int fd[2], int job)
{
	int		cmdfd[2];
	int		pipefd[2];
	pid_t	pid;

	if (!(root) || !(root->left))
		return (EXIT_SUCCESS);
	if (root->right)
	{
		if (pipe(pipefd) == -1)
			return (pipeerror());
		fcntl(pipefd[0], F_SETFD, FD_CLOEXEC);
		fcntl(pipefd[1], F_SETFD, FD_CLOEXEC);
		cmdfd[0] = fd[0];
		cmdfd[1] = pipefd[1];
		if ((pid = execcmd(root->left, cmdfd, job, 1)) == -1)
			return (-1);
		fd[0] = pipefd[0];
		execpipes(root->right, fd, job);
		waitpid(pid, 0, 0);
		return (0);
	}
	else
		return (execcmd(root->left, fd, job, 0));
}
