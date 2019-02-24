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

int		execcmd(t_astree *root, int fd[2], int job, int isfork)
{
#ifdef EXECUTE_DEBUG
printf("execcmd:%d\n", root->type);
#endif
	/* if (root->type == FUNCTION) */
	/* 	return (execfunc(root, fd, job, 0)); */
	/* if (root->type == FOR) */
	/* 	return (execfor(root, fd, job, 0)); */
	if (root->type == CASE)
		return (execcase(root, fd, job, 0));
	/* if (root->type == WHILE) */
	/* 	return (execwhile(root, fd, job, 0)); */
	/* if (root->type == UNTIL) */
	/* 	return (execuntil(root, fd, job, 0)); */
	/* if (root->type == SELECT) */
	/* 	return (execselect(root, fd, job, 0)); */
	if (root->type == IF)
		return (execif(root, fd, job, 0));
	/* if (root->type == ARITH) */
	/* 	return (execarith(root, fd, job, 0)); */
	/* if (root->type == COND) */
	/* 	return (execcond(root, fd, job, 0)); */
	if (root->type == SUBSHELL)
		return (execsubshell(root, fd, job, isfork));
	if (root->type == COMMAND)
		return (execscmd(root, fd, job, isfork));
	/* return (execlist1(root, fd, job, 0)); */
	return (-228);
}
