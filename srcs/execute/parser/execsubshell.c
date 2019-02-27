/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsubshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:25:54 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/24 19:25:54 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                /
**        SUBSHELL
**       /
** CMPLST
*/

#include "execute.h"

int		execsubshell(t_astree *root, int fd[2], int job, int isfork)
{
	int pid;
	int status;

	if (!isfork)
		pid = xfork();
	if (isfork || !pid)
		exit(execlist1(root->left, fd, job, 1));
	xwaitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
