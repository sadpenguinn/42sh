/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:39:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 19:18:21 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execcmd(t_astree *root, int fd[2], int flag)
{
	if (root->type == FUNCTION)
		return (execfunc(root, fd, flag));
	if (root->type == FOR)
		return (execfor(root, fd, flag));
	if (root->type == CASE)
		return (execcase(root, fd, flag));
	if (root->type == WHILE)
		return (execwhile(root, fd, flag));
	if (root->type == UNTIL)
		return (execuntil(root, fd, flag));
	if (root->type == SELECT)
		return (execselect(root, fd, flag));
	if (root->type == IF)
		return (execif(root, fd, flag));
	if (root->type == ARITH)
		return (execarith(root, fd, flag));
	if (root->type == COND)
		return (execcond(root, fd, flag));
	if (root->type == COMMAND)
		return (execsimple(root, fd, flag));
	return (execlist1(root, fd, flag));
}
