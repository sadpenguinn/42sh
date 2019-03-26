/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 21:34:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	print_job(pid_t pid)
{
	ft_putstr_fd("[", STDERR_FILENO);
	ft_putnbr_fd(vector_get_len(g_jobs), STDERR_FILENO);
	ft_putstr_fd("] ", STDERR_FILENO);
	ft_putnbr_fd(pid, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int			addjob(int state, pid_t pid)
{
	t_job	job;

	if (pid > 0)
	{
		job.pids = vector_create(sizeof(pid_t));
		vector_push_back(&(job.pids), &pid);
	}
	else
	{
		if (!(job.pids = g_pids))
			return (EXIT_FAILURE);
		g_pids = 0;
	}
	pid = *(pid_t*)vector_back(job.pids);
	waitpid(pid, &(job.status), WNOHANG);
	g_job = 1;
	job.sub_pids = g_sub_pids;
	g_sub_pids = 0;
	job.state = state;
	vector_push_back(&g_jobs, &job);
	print_job(pid);
	return (EXIT_FAILURE);
}
