/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:25:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 19:56:59 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>

int		execpipes(t_astree	*root, int fd[2], int flag)
{
	int		cmdfd[2];
	int		pipefd[2];

	if (!(root) || !(root->left) || !(root->right))
		return (-1);
	if (root->right)
	{
		if (pipe(pipefd) == -1)
			return (pipeerror());
		fcntl(pipefd[0], F_SETFD, FD_CLOEXEC);
		fcntl(pipefd[1], F_SETFD, FD_CLOEXEC);
		cmdfd[0] = fd[0];
		cmdfd[1] = pipefd[1];
		if (execcmd(root->left, cmdfd, flag) == -1)
			return (-1);
		fd[0] = pipefd[0];
		return (execpipes(root->right, fd, flag));
	}
	else
		return (execcmd(root->left, fd, flag));
}
