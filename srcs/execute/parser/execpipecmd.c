/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:01:57 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 13:41:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execpipecmd(t_astree *root, int fd[2], int flag, void *ppid)
{
	void	*pipepid;

	if (!(root) || !(root->left))
		return (-1);
	if (root->type == NOT)
		return (!execpipecmd(root->left, fd, flag, ppid));
	pipepid = (ppid ? ppid : vector_create(sizeof(pid_t)));
	if (root->left->type == REST)
		execpipes(root->left, fd, flag, pipepid);
	if (root->left->type == COMMAND)
		execcmd(root->left, fd, flag, pipepid);
// XXX - wait pipes	
	return (777);
}
