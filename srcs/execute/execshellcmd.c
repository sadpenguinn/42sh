/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execshellcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:39:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execshellcmd(t_astree *root, int fd[2], int job, int isfork)
{
	if (root->type == FUNCTION)
		return (1);
	if (root->type == FOR)
		return (1);
	if (root->type == CASE)
		return (execcase(root, fd, job, 0));
	if (root->type == WHILE)
		return (1);
	if (root->type == UNTIL)
		return (1);
	if (root->type == SELECT)
		return (1);
	if (root->type == IF)
		return (execif(root, fd, job, 0));
	if (root->type == ARITH)
		return (1);
	if (root->type == COND)
		return (1);
	if (root->type == SUBSHELL)
		return (execsubshell(root, fd, job, isfork));
	if (root->type == COMMAND)
		return (execscmd(root, fd, job, isfork));
	return (execlist1(root, fd, job, 0));
}
