/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:48:24 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "builtins.h"
#include "shell.h"

static int		fg_parse_args(char **args)
{
	if (!args[1])
		return (1);
	if (args[1] && !ft_str_is_numeric(args[1]))
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[1]);
		return (0);
	}
	else if (args[1] && args[2] != 0)
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[2]);
		return (0);
	}
	else if (!ft_atoi(args[1]))
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "fg", args[1]);
		return (0);
	}
	return (1);
}

static size_t	fg_get_index(char **av)
{
	size_t	i;
	size_t	len;

	if (!(len = vector_get_len(g_jobs)))
	{
		sputcmderr("No running jobs", "fg", av[1] ? av[1] : "current");
		return (0);
	}
	i = len;
	if (av[1] && ft_str_is_numeric(av[1]))
	{
		i = (size_t)ft_atoi(av[1]);
		if (i > len)
		{
			sputcmderr("No running jobs", "fg", av[2]);
			return (0);
		}
	}
	return (i);
}

int				built_bg(char **av, char **env)
{
	t_job	*job;
	pid_t	pid;
	pid_t	pgid;
	size_t	i;

	env = NULL;
	if (!(fg_parse_args(av)) || !(i = fg_get_index(av)))
		return (SHERR_ERR);
	i--;
	job = (t_job *)vector_get_elem(g_jobs, i);
	if (job->state == JOB_RUN)
	{
		ft_putstr_fd("bg: job already in background\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pid = *(pid_t *)vector_back(job->pids);
	pgid = getpgid(pid);
	ft_putstr_fd("[", STDERR_FILENO);
	ft_putnbr_fd(i, STDERR_FILENO);
	ft_putstr_fd("] ", STDERR_FILENO);
	ft_putnbr_fd(pid, STDERR_FILENO);
	ft_putstr_fd(" continued\n", STDERR_FILENO);
	job->state = JOB_RUN;
	killpg(pgid, SIGCONT);
	return (SHERR_OK);
}
