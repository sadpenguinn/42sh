/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:27:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/01 12:39:51 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell.h"
#include "readline.h"

extern int		g_execerr;

static int		g_signal;

void			vkill(void *cmd)
{
	kill(g_signal, (int)cmd);
}

void			sigtstp(void)
{
	pid_t	*pid;

	/* if (g_pids) */
	/* 	vector_foreach(g_pids, vkill); */

	/* while ((pid = vector_pop_back(&g_pids))) */
	/* { */
	/* 	kill(pid, SIGSTOP); */
	/* 	vector_push_back(&g_jobs, &pid); */
	/* } */

	if (!vector_get_len(g_pids))
		return ;
	pid = vector_back(g_pids);
	vector_push_back(&g_jobs, pid);
	vector_pop_back(&g_pids);
	/* kill(*pid, SIGSTOP); */
}

void			shell_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGTSTP)
		sigtstp();
	if (sig == SIGINT)
	{
		g_vi_mode = INSERT_MODE;
		dup2(0, 0);
	}
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTSTP)
	{
		if (g_pids)
		{
			g_execerr = 1;
			vector_foreach(g_pids, vkill);
		}
	}
}

void			init_signals(void)
{
	struct sigaction	action;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGTSTP);
	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = shell_handler;
	action.sa_mask = set;
	sigaction(SIGINT, &action, 0);
	sigaction(SIGQUIT, &action, 0);
	sigaction(SIGTSTP, &action, 0);
}
