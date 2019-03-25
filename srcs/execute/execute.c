/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:46:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/25 19:54:43 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "signals.h"

pid_t	g_pgid;
int		g_isjob = 0;
int		g_job = 0;
void	*g_sub_pids = 0;
int		g_run;

int		execute(t_astree *root)
{
	int		res;
	int		fd[2];
	int		tmp_err;
	int		execute(t_astree *root);

	g_pgid = -1;
	tmp_err = g_execerr;
	g_isjob = 0;
	g_execerr = 0;
	g_run = 1;
	if (!root)
		return (EXIT_FAILURE);
	fd[0] = 0;
	fd[1] = 1;
	res = execlist1(root, fd, 0);
	tcsetpgrp(0, getpgrp());
	g_execerr = tmp_err;
	g_run = 0;
	return (res);
}
