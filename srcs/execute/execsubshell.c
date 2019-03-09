/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsubshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:25:54 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                /
**        SUBSHELL
**       /
** CMPLST
*/

#include "execute.h"

int		execsubshell(t_astree *root, int fd[2], int isfork)
{
	int pid;

	if (!isfork)
		pid = xfork();
	if (isfork || !pid)
		exit(execlist1(root->left, fd, 1));
	return (xwaitpid(pid, 0));
}
